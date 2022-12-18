// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q; // x, y, steps, obstac_left
        
        vector<vector<int>> grid_obs_left(m, vector<int> (n, 0));
        grid_obs_left[0][0] = k;

        q.push({0, 0, 0, k});

        while(!q.empty()) {
            vector<int> front = q.front();
            q.pop();
            int x = front[0], y = front[1], curr_steps = front[2], curr_obs = front[3];

            // Reached the destination
            if(x==m-1 and y==n-1) {
                return curr_steps;
            }

            // If there is obstac
            if(grid[x][y]==1) {
                curr_obs--;
                if(curr_obs<0) {
                    continue;
                }
            }

            grid_obs_left[x][y] = max(grid_obs_left[x][y], curr_obs);

            for(int i=0;i<4;i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx<0 || yy<0 || xx>=m || yy>=n || grid_obs_left[xx][yy] > curr_obs)
                    continue;
                q.push({xx,yy,curr_steps+1, curr_obs});
            }
        }
        return -1; 
    }
};