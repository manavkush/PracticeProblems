// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ll = 0, sz = 1;

        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]) {
                dp[i][i+1] = 1; 
                ll = i;
                sz = 2;
            }
        }
        
        
        for(int j=3;j<=n;j++) { //length
            for(int i=0;i<=n-j;i++) {   // starting index
                if(s[i]==s[i+j-1] and dp[i+1][i+j-2]) {
                    dp[i][i+j-1] = 1;
                    if(j>sz) {
                        ll = i;
                        sz = j;
                    }
                }
            }
        }
        return s.substr(ll, sz);
        
    }
};