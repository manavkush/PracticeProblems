// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

class Solution {
public:
    string smallestSubsequence(string s) {
        int len = s.length();
        vector<int> seen(26, 0);
        vector<int> last(26, -1);
        for(int i=len-1;i>=0;i--) {
            char c = s[i];
            if(last[c-'a']==-1)
                last[c-'a'] = i;
            
        }
        // for(auto &x: last) {
        //     cout<<x<<" ";
        // }
        stack<char> st;
        seen = vector<int> (26, 0);
        for(int i=0;i<len;i++) {
            char c = s[i];
            if(seen[c-'a']++) continue;
            while(!st.empty() and (st.top()>c) and (last[st.top()-'a']>i)) {
                seen[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
        }
        string str;
        while(!st.empty()) {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};