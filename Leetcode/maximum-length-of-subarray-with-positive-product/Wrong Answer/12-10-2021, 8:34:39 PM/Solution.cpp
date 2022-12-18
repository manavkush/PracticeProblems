// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n+1, 0), neg(n+1, 0);
        pos[0] = -1;
        neg[0] = -1;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                pos[i+1] = -1;
                neg[i+1] = -1;
            } else if(nums[i] < 0) {
                pos[i+1] = max(neg[i]+1, 0);
                neg[i+1] = max(pos[i]+1, 1);
            } else {
                pos[i+1] = max(pos[i]+1, 1);
                neg[i+1] = min(neg[i]+1, 0);
            }
        }
        int res = 0;
        for(int i=1;i<=n;i++) {
            res = max(res, pos[i]);
        }
        return res;
    }
};