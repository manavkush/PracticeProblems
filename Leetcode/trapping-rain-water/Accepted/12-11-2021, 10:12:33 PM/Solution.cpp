// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        
        int sum = 0;
        
        for(int i=0;i<n;) {
            if(st.empty() || height[st.top()] >= height[i]) {
                st.push(i++);
            } else {
                int curr = height[st.top()];
                st.pop();
                sum += st.empty() ? 0 : (min(height[i], height[st.top()])-curr)*(i-st.top()-1);
            }
        }
        return sum;
    }
};