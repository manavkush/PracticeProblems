// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> st;
        a.push_back(0);
        int n = a.size();
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            while((!st.empty()) and a[i] < a[st.top()] ) {
                int top = st.top(); st.pop();
                int l = (st.empty() ? -1 : st.top());
                ans = max(ans, a[top]*(i-l-1));
            }
            st.push(i);
        }
        
        return ans;
    }
    
};