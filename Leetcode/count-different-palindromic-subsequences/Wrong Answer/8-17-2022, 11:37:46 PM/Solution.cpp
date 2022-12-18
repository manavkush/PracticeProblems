// https://leetcode.com/problems/count-different-palindromic-subsequences

class Solution {
private:
    const int mod = 1e9+7;
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<vector<long>> dp(n, vector<long> (n));
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        for(int i=n-2;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                if(s[i]==s[j]) {
                    dp[i][j] = (dp[i+1][j]+dp[i][j-1])%mod;
                } else {
                    dp[i][j] = (dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%mod;
                }
            }
        }
        return dp[0][n-1];
    }
};