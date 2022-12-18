// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n+1, 0), neg(n+1, 0);
        pos[0] = 0;
        neg[0] = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                pos[i+1] = 0;
                neg[i+1] = 0;
            } else if(nums[i] < 0) {
                pos[i+1] = neg[i]==0 ? 0 : neg[i]+1;
                neg[i+1] = pos[i]+1;
            } else {
                pos[i+1] = pos[i]+1;
                neg[i+1] = neg[i] == 0 ? 0 : neg[i]+1;
            }
        }
        int res = 0;
        for(int i=1;i<=n;i++) {
            res = max(res, pos[i]);
        }
        return res;
    }
};