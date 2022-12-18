// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(s[i]==s2[j]) {
                    dp[i+1][j+1] = 1+dp[i][j];
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return n-dp[n][n];
    }
};