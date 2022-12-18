// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                st.push(s[i]);  
                continue;
            } 
            
            if(st.empty())   return false;
            if(s[i]==']' and st.top()!='[') return false;
            if(s[i]=='}' and st.top()!='{') return false;
            if(s[i]==')' and st.top()!='(') return false;
            
            st.pop();
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};