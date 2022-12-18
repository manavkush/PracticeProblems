// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int pos, neg;
        pos = 0;
        neg = 0;
        int res = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                pos = 0;
                neg = 0;
            } else if(nums[i] < 0) {
                int temp = pos;
                pos = neg == 0 ? 0 : neg+1;
                neg = temp+1;
            } else {
                pos = pos+1;
                neg = neg == 0 ? 0 : neg+1;
            }
            res = max(res, pos);
        }
        return res;
    }
};