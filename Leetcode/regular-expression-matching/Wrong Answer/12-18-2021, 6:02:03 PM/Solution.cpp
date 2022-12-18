// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));
        // bool dp[n+1][m+1] = {0};
        dp[0][0] = 1;
        
        for(int j=0;j<m;j++) {
            for(int i=0;i<n;i++) {
                if(s[i]==p[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else if(p[j]=='.') {
                    dp[i+1][j+1] = dp[i][j];
                } else if(p[j]=='*') {
                    if(p[j-1]=='.' || p[j-1]=='*') {
                        dp[i+1][j+1] = dp[i+1][j] || dp[i][j];
                    } else {
                        if(s[i]==p[j-1])
                            dp[i+1][j+1] = dp[i+1][j] || dp[i][j];
                        else 
                            dp[i+1][j+1] = dp[i][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};