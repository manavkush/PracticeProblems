// https://leetcode.com/problems/construct-smallest-number-from-di-string

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        stack<char> st;
        string ans;
        int i=0;
        while(1) {
            // cout<<ans<<endl;
            st.push('1'+ i);
            if(i==n || pattern[i]=='I') {
                while(!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
            }
            i++;
            if(i>n)
                break;
        }
        return ans;
    }
};