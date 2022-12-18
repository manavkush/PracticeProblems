// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int prev = 0;
        stack<int> st;
        st.push(-1);
        int n = s.length();
        int ans = 0;
        vector<int> dp(n+1, 0);
        for(int i=1;i<n;i++) {
            if(s[i]=='(') {
                continue;
            } else {
                if(s[i-1]=='(')
                    dp[i+1] = dp[i-1]+2;
                else {
                    int len = dp[i-1];
                    if(s[i-len-1]=='(') {
                        dp[i+1] = 2+dp[i]+dp[i-len];
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};