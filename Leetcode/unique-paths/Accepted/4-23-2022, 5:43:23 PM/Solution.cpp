// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(i>0) {
                    dp[i-1][j] = dp[i][j];
                } 
                if(j>0) {
                    dp[i][j-1] += dp[i][j];
                }
            }
        }
        return dp[0][0];
    }
};