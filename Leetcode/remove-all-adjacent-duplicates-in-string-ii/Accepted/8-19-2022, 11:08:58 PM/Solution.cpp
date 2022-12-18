// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        int n = s.length();
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++) {
            int cnt = 0;
            if(st.empty()) {
                st.push({s[i], 1});
            } else {
                if(st.top().first==s[i]) {
                    auto val = st.top().second;
                    st.pop();
                    if((val+1)%k!=0) {
                        st.push({s[i], (val+1)%k});
                    }
                } else {
                    st.push({s[i], 1});
                }
            }
        }
        while(!st.empty()) {
            auto top = st.top(); st.pop();
            ans += string(top.second, top.first);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};