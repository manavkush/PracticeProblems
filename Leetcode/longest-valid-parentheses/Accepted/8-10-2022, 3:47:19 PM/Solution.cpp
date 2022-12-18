// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int prev = 0;
        stack<int> st;
        st.push(-1);
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                ans = max(ans, i-st.top());
            }
        }
        return ans;
    }
};