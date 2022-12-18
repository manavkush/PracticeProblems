// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        int dp[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        // dp[1][0] = max(dp[0][0], dp[0][1]);
        // dp[1][1] = nums[1];
        for(int i=1;i<n;i++) {
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = dp[i-1][0]+nums[i];
            // cout<<dp[i][0]<<" "<<dp[i][1]<<"   ";
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};