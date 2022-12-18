// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        vector<int> small(n);
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push(i);
            } else {
                while((!st.empty()) and a[i] < a[st.top()] ) {
                    ans = max(ans, a[st.top()]*(i-st.top()));
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()) {
            ans = max(ans, a[st.top()]*(n-st.top()));
            st.pop();
        }
        int prev = -1;
        for(int i=0;i<n;i++) {
            if(a[i] == 0) {
                ans = max(ans, i-prev-1);
                prev = i;
            }
        }
        ans = max(ans, n - prev -1);
        return ans;
    }
    
};