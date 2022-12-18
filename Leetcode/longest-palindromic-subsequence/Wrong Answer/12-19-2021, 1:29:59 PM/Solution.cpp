// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n==1)    return 1;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        int ans = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(s[i]==s[j]) {
                    dp[j][i] = max(dp[j+1][i-1] + 2, dp[j][i]);
                } else {
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]);                    
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
        
    }
};