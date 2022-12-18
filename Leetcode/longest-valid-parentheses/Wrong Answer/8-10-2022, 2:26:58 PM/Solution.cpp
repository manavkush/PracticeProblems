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
                if(st.top()==-1) {
                    ans = i-prev;
                    prev = i+1;
                } else {
                    ans = max(ans, i-st.top()+1);
                    st.pop();
                    if(st.top()==-1) {
                        ans = max(ans, i-prev+1);
                    }
                }
            }
        }
        if(st.top()==-1) {
            ans = max(ans, n-prev);
        } else {
            ans = max(ans, n-st.top()-1);
        }
        return ans;
    }
};