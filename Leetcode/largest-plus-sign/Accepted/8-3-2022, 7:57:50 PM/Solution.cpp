// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int> (n, 1));
        for(int i=0;i<mines.size();i++) {
            grid[mines[i][0]][mines[i][1]] = 0;
        }
        vector<vector<int>> left(n+1 , vector<int> (n+1, 0)), right(n+1, vector<int> (n+1, 0));
        vector<vector<int>> up(n+1 , vector<int> (n+1, 0)), down(n+1, vector<int> (n+1, 0));
        
        for(int i=0;i<n;i++) {
            stack<int> st;
            int prev = -1;
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    st.push(j);
                    left[i][j] = prev;
                } else {
                    while(!st.empty()) {
                        right[i][st.top()] = j;
                        st.pop();
                    }
                    prev = j;
                }
            }
            while(!st.empty()) {
                right[i][st.top()] = n;
                st.pop();
            }
        }
        
        for(int j=0;j<n;j++) {
            stack<int> st;
            int prev = -1;
            for(int i=0;i<n;i++) {
                if(grid[i][j]==1) {
                    st.push(i);
                    up[i][j] = prev;
                } else {
                    while(!st.empty()) {
                        down[st.top()][j] = i;
                        st.pop();
                    }
                    prev = i;
                }
            }
            while(!st.empty()) {
                down[st.top()][j] = n;
                st.pop();
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                // cout<<left[i][j]<<" ";
                if(grid[i][j]==1) {
                    int curr = min({j-left[i][j], right[i][j]-j, i-up[i][j], down[i][j]-i});
                    // cout<<curr<<" ";
                    ans = max(ans, curr);
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};