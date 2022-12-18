// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        // States[i][j] --> idx, length
        
        int start = 0;
        int len = 1;
        
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]) {
                dp[i][i+1] = 1; 
                if(len<2) {
                   start = i;
                   len = 2;
                }
            }
        }
        
        for(int length=3;length<=n;length++) {
            for(int i=0;i<=n-length; i++) {
                if(s[i]==s[i+length-1] && dp[i+1][i+length-2]) {
                    if(len<length) {
                        len = length;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};