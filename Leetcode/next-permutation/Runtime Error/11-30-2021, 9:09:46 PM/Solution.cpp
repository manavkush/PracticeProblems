// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                idx = i;
                for(int j=n;j>=i;j--) {
                    if(nums[j]>nums[i]) {
                        swap(nums[j], nums[i]);
                        reverse(nums.begin()+idx+1, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};