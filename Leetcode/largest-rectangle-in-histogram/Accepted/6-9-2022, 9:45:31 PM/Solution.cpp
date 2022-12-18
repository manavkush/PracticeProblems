// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> smallbefore(n, -1);
        vector<int> smallafter(n, n);
        stack<int> st;
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push(i);
            } else {
                while(!st.empty() and heights[st.top()]>heights[i]) {
                    smallafter[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(st.empty()) {
                st.push(i);
            } else {
                while(!st.empty() and heights[st.top()]>heights[i]) {
                    smallbefore[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            int curr = (smallafter[i]-smallbefore[i]-1)*heights[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};