// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        int n = s.length();
        int curr = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                st.push(s[i]);
            } else {
                if(st.empty()) {
                    curr = 0;
                } else {
                    curr+=2;
                    st.pop();
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};