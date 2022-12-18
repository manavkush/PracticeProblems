// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
private:
    vector<int> dr = {0, 0, 1, -1}, dc = {1, -1, 0, 0};
    bool check(int rr, int cc, vector<vector<int>> &heights, vector<vector<int>>&vis, int curr_height) {
        int m = heights.size();
        int n = heights[0].size();
        if(rr<0 || cc<0 || rr>=m || cc>=n || vis[rr][cc] || heights[rr][cc] < curr_height) {
            return false;
        }
        return true;
    }
    void bfs(vector<vector<int>> &heights, vector<vector<int>> &vis, vector<vector<int>> &grid, queue<int> &qr, queue<int> &qc) {
        while(!qr.empty()) {
            int r = qr.front(), c = qc.front();
            qr.pop(), qc.pop();
            
            grid[r][c]++;
            int curr_height = heights[r][c];

            for(int i=0;i<4;i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(check(rr, cc, heights, vis, curr_height)) {
                    qr.push(rr);
                    qc.push(cc);
                    vis[rr][cc] = 1;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> grid(m, vector<int> (n, 0)), vis(m, vector<int> (n, 0));
        queue<int> qr, qc;
        
        for(int i=0;i<n;i++) {
            qr.push(0);
            qc.push(i);
            vis[0][i] = 1;
        }
        for(int i=1;i<m;i++) {
            qr.push(i);
            qc.push(0);
            vis[i][0] = 1;
        }
        bfs(heights, vis, grid, qr, qc);
        vis = vector<vector<int>> (m, vector<int> (n, 0));
        for(int i=0;i<n;i++) {
            qr.push(m-1);
            qc.push(i);
            vis[m-1][i] = 1;
        }
        for(int i=0;i<m-1;i++) {
            qr.push(i);
            qc.push(n-1);
            vis[i][n-1] = 1;
        }
        bfs(heights, vis, grid, qr, qc);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]>1) {
                    ans.push_back({i, j});
                }
            }
            // cout<<endl;
        }
        return ans;
        
    }
};