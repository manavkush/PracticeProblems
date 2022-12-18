// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        dp[0][0] = 1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i+1<m) dp[i+1][j] += dp[i][j];
                if(j+1<n) dp[i][j+1] += dp[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};