// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n==1)    return 1;
        vector<int> dp(n);  // max length of 
        
        for(int i=0;i<n;i++) {
            dp[i] = 1;
        }
        
        int ans = 1;
        for(int j=1;j<n;j++) {
            int prev = 0;
            for(int i=j-1;i>=0;i--) {
                if(s[i]==s[j]) {
                    int temp = dp[i];
                    dp[i] = max(prev + 2, dp[i]);
                    prev = temp;
                } else {
                    int temp = dp[i];
                    dp[i] = max(dp[i], dp[i+1]);
                    prev = temp;
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
        
    }
};