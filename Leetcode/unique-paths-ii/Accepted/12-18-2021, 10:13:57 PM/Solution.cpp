// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = matrix[0][0] == 0 ? 1 : 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 && j==0) continue;
                if(matrix[i][j]==1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[max(i-1, 0)][j] + dp[i][max(0, j-1)];
                }
            }
        }
        for(int i= 0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<dp[i][j]<<" ";
            }
            
            cout<<endl;
        }
        return dp[n-1][m-1];
    }
};