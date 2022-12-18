// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        int n = s.length();
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=i;j<n and s[i]==s[j];j++) {
                cnt++;
            }
            int rem = cnt%k;
            if(rem>0) {
                if(st.empty()) {
                    st.push({s[i], rem});
                } else if(st.top().first == s[i]) {
                    auto top = st.top(); st.pop();
                    top.second = (top.second + rem)%k;
                    if(top.second) {
                        st.push(top);
                    }
                } else {
                    st.push({s[i], rem});
                }
            }
            i += cnt-1;
        }
        while(!st.empty()) {
            auto top = st.top(); st.pop();
            ans += string(top.second, top.first);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};