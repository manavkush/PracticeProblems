// https://leetcode.com/problems/maximal-rectangle

class Solution {
private:
    int maxarea(vector<int> &vec) {
        vec.push_back(-1);
        stack<int> st;
        int ans = 0;
        for(int i=0;i<vec.size();i++) {
            while(!st.empty() and vec[st.top()]>=vec[i]) {
                int height = vec[st.top()];
                st.pop();
                int width = (st.empty() ? i : i-st.top()-1);
                ans = max(ans, height*width);
            }
            st.push(i);
        }
        vec.pop_back();
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> grid(rows, vector<int> (cols, 0));
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                grid[i][j] = matrix[i][j]-'0';
            }
        }
        
        int ans = 0;
        vector<int> height(cols);
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j]) height[j]++;
                else height[j] = 0;
            }
            ans = max(ans,maxarea(height));
        }
        return ans;
    }
};