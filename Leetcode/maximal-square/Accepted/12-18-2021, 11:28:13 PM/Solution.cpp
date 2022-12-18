// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        int ans = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]!='1') 
                    continue;
                
                if(dp[i][j+1]==dp[i+1][j]) {
                    int sz = dp[i][j+1];
                    
                    if(matrix[i-sz][j-sz]=='1') 
                        dp[i+1][j+1] = sz+1;
                    else 
                        dp[i+1][j+1] = sz;
                } else {
                    dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1])+1;
                }
                ans = max(ans, dp[i+1][j+1]);
            }
        }
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=m;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans*ans;
    }
    
};