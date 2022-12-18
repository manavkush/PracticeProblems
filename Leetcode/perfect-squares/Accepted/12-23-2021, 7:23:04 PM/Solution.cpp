// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> dp(n+1, INT_MAX-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int sum = 2;sum<=n;sum++) {
            for(int i=1;i<=sqrt(sum);i++) {
                dp[sum] = min(dp[sum], 1+dp[sum-i*i]);
            }
        }
        // for(int i=1;i<n;i++)
        return dp[n];
    }
};