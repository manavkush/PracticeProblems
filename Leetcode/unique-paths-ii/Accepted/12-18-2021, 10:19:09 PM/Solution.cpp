// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        dp[1][0] = 1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(matrix[i-1][j-1]==1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};