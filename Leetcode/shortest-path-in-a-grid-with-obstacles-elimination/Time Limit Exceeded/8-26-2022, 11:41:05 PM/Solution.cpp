// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> stops(n, vector<int> (m, INT_MAX));
        vector<vector<int>> vis(n, vector<int> (m, INT_MAX));

        vis[0][0] = 0;
        
        queue<vector<int>> q;
        
        q.push({0, 0, 0, 0});   // steps, obstacles, row, col
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        
        while(!q.empty()) {
            auto top = q.front(); q.pop();
            int row = top[2], col = top[3], steps = top[0], obstac = top[1];
            
            if(row==n-1 and col == m-1)
                return steps;
            
            if(vis[row][col]<obstac)
                continue;
            
            else if(stops[row][col]>=obstac) {
                for(int i=0;i<4;i++) {
                    int rr = row + dr[i];
                    int cc = col + dc[i];
                    if(rr<0 || cc<0 || rr>=n || cc>=m) {
                        continue;
                    }
                    if(grid[rr][cc]) {
                        if(obstac<k and vis[rr][cc]>obstac +1) {
                            q.push({steps+1, obstac+1, rr, cc});
                        }
                    } else {
                        if(vis[rr][cc]>obstac) {
                            q.push({steps+1, obstac, rr, cc});
                        }
                    }
                }
            }
        }
        return -1;
    }
};