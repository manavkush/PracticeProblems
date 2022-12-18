// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int> (n, INT_MAX));
        for(int i=0;i<mines.size();i++) {
            grid[mines[i][0]][mines[i][1]] = 0;
        }
        // vector<vector<int>> left(n+1 , vector<int> (n+1, 0)), right(n+1, vector<int> (n+1, 0));
        // vector<vector<int>> up(n+1 , vector<int> (n+1, 0)), down(n+1, vector<int> (n+1, 0));
        
        // left to right
        for(int i=0;i<n;i++) {
            stack<int> st;
            int prev = -1;
            for(int j=0;j<n;j++) {
                if(grid[i][j]!=0) {
                    st.push(j);
                    grid[i][j] = min(grid[i][j], j-prev);
                } else {
                    while(!st.empty()) {
                        grid[i][st.top()] = min(grid[i][st.top()],j-st.top());
                        st.pop();
                    }
                    prev = j;
                }
            }
            while(!st.empty()) {
                grid[i][st.top()] = min(n-st.top(), grid[i][st.top()]);
                st.pop();
            }
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        
        // top to bottom
        for(int j=0;j<n;j++) {
            stack<int> st;
            int prev = -1;
            for(int i=0;i<n;i++) {
                if(grid[i][j]!=0) {
                    st.push(i);
                    grid[i][j] = min(grid[i][j],i-prev);
                } else {
                    while(!st.empty()) {
                        grid[st.top()][j] = min(grid[st.top()][j], i-st.top());
                        st.pop();
                    }
                    prev = i;
                }
            }
            while(!st.empty()) {
                grid[st.top()][j] = min(grid[st.top()][j], n-st.top());
                st.pop();
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                // cout<<left[i][j]<<" ";
                // if(grid[i][j]!=0) {
                //     int curr = min({j-left[i][j], right[i][j]-j, i-up[i][j], down[i][j]-i});
                    // cout<<grid[i][j]<<" ";
                ans = max(ans, grid[i][j]);
                // }
            }
            // cout<<endl;
        }
        return ans;
    }
};