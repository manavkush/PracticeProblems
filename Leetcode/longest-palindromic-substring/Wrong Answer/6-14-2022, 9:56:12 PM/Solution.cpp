// https://leetcode.com/problems/longest-palindromic-substring

class Solution {

public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        int len = 1;
        int first = 0;
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1])
                dp[i][i+1] = 1;
        }
        
        for(int sz=3;sz<=n;sz++) {
            for(int i=0;i<n-sz+1;i++) {
                if(s[i]==s[i+sz-1] and (dp[i+1][i+sz-2])) {
                    dp[i][i+sz-1] = 1;
                    if(sz>len) {
                        len = sz;
                        first = i;
                    }
                }
            }
        }
        return s.substr(first, len);
    }
};