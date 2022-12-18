// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                swap(nums[i], nums[i+1]);
                for(int j=i+2;j<n;j++) {
                    if(nums[j]>nums[j-1]) swap(nums[j], nums[j-1]);
                    else break;
                }
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};