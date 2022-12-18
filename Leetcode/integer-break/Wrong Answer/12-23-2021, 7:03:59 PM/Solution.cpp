// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int sum=2;sum<=n;sum++) {
            for(int j=1;j<sum;j++) {
                dp[sum] = max(dp[sum], dp[j]*dp[sum-j]);
            }
        }
        return dp[n];
    }
};