// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n+1);
        vector<int> neg(n+1);
        pos[0] = neg[0] = 1;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                pos[i+1] = 0;
                neg[i+1] = 0;
            } else if(nums[i] > 0) {
                pos[i+1] = max(nums[i], pos[i]*nums[i]);
                neg[i+1] = min(nums[i], neg[i]*nums[i]);
            } else {
                pos[i+1] = max(nums[i], neg[i]*nums[i]);
                neg[i+1] = min(nums[i], pos[i]*nums[i]);
            }
        }
        int high = INT_MIN;
        for(int i=0;i<n;i++) {
            high = max(high, pos[i+1]);
        }
        return high;
    }
};