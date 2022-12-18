// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n+1, 0), neg(n+1, 0);
        pos[0] = 1;
        neg[0] = 1;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                pos[i+1] = 0;
                neg[i+1] = 0;
            } else if(nums[i] < 0) {
                pos[i+1] = max(neg[i]*nums[i], nums[i]);
                neg[i+1] = min(pos[i]*nums[i], nums[i]);
            } else {
                pos[i+1] = max(pos[i]*nums[i], nums[i]);
                neg[i+1] = min(neg[i]*nums[i], nums[i]);
            }
        }
        int res = INT_MIN;
        for(int i=1;i<=n;i++) {
            res = max(res, pos[i]);
        }
        return res;
        
    }
};