// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans;
        int curr = 0;
        stack<char> st;
        for(int i=0;i<n;i++) {
            if(st.empty() || curr>=k) {
                st.push(num[i]);
                continue;
            }
            while(!st.empty() and curr<k and num[i]<st.top()) {
                curr++;
                st.pop();
            }
            st.push(num[i]);
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        while(ans.length()>1 and (ans.back()=='0')) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};