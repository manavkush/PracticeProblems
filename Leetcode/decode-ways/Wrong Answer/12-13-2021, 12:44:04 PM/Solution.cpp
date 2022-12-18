// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        if(s[0]=='0')   return 0;
                        
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[0] = 1;
        bool flag = 0;
        for(int i=1;i<n;i++) {
            if(s[i]=='0') {
                if(s[i-1]=='1' || s[i-1]=='2') {
                    dp[i+1] = dp[i-1];
                } else {
                    flag = 1;
                    break;
                }
            }
            if(s[i-1]=='1') {
                dp[i+1] = dp[i] + dp[i-1]; 
            } else if(s[i-1]=='2' and s[i]-'0'<7) {
                dp[i+1] = dp[i] + dp[i-1];
            } else {
                dp[i+1] = dp[i];
            }
        }
        
        return flag ? 0 : dp[n];
    }
};