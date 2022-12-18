// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        vector<int> diff(n);
        for(int i=1;i<n;i++) {
            diff[i] = nums[i] - nums[i-1];
        }
        vector<int> dp(4001, 0);
        long sum = 0;
        for(int i=2;i<n;i++) {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2]) {
                dp[i] = dp[i-1]+1;
                sum += dp[i];
            } else {
                dp[i] = 0;
            }
        }
        return sum;
        // dp[i] --> stores the number of series ending at i i.e. with diff nums[i]-nums[i-1];
    }
};