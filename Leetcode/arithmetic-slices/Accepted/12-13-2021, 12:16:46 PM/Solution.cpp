// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;

        long long sum = 0;
        int prev = 0;
        for(int i=2;i<n;i++) {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2]) {
                prev = prev+1;
                sum += prev;
            } else {
                prev = 0;
            }
        }
        return sum;
        // dp[i] --> stores the number of series ending at i i.e. with diff nums[i]-nums[i-1];
    }
};