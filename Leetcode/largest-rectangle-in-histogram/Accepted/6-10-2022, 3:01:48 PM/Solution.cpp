// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> st;  
        // We'll keep a stack which will store elements in increasing height order.
        // If the new element is greater than equalto the top of stack, we'll push in stack
        // Else we'll pop out the top and get the area with that as the height of rectangle
        // We'll do this till the top of stack is greater than the current
        // For every popped index, the width will be [ prev element in stack to the current idx ]
        
        a.push_back(-1);    // pushing an element smaller than everyone in the back of array
        int n = a.size();
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            while(!st.empty() and a[st.top()] > a[i]) {
                int height = a[st.top()]; 
                st.pop();
                int width = (st.empty() ? (i) : (i-st.top()-1));
                ans = max(ans, height*width);
            }
            st.push(i);
        }
        
        return ans;
    }
    
};