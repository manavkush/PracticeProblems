// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
        }
        if(sum&1) {
            return 0;
        }
        sum = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, 0));    // index, 
        
        for(int i=0;i<n;i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {            
                if(j<nums[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(dp[i][sum]==1) return 1;
        }
        return 0;
    }
};