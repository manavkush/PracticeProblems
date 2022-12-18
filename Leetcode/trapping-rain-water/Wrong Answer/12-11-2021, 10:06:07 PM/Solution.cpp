// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        vector<int> next(n+1, -1), prev(n+1, -1);
        int sum = 0;
        
        for(int i=0;i<n;i++) {
            if(st.empty() || st.top() < height[i]) {
                st.push(height[i]);
            } else {
                int curr = st.top();
                st.pop();
                sum += st.empty() ? 0 : min(height[i], height[st.top()])*(i-st.top()-1);
            }
        }
        return sum;
    }
};