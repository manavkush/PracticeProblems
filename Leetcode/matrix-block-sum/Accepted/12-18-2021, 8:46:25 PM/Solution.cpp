// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int> > dp(n+1, vector<int> (m+1, 0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                ans[i-1][j-1] = dp[min(i+k, n)][min(j+k, m)] - dp[max(i-k-1,0)][min(j+k,m)] - dp[min(i+k, n)][max(j-k-1,0)] + dp[max(i-k-1,0)][max(j-k-1,0)]; 
            }
        }
        return ans;
    }
};