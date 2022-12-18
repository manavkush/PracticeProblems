// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        
        vector<vector<int>> max_obs(n, vector<int> (m, -1));
        max_obs[0][0] = k;
        
        queue<vector<int>> q;   // x,y,steps,obstac
        q.push({0, 0, 0, k});
        
        while(!q.empty()) {
            vector<int> front = q.front();
            q.pop();
            
            int x = front[0], y = front[1], steps = front[2], obs_left=front[3];
            
            if(grid[x][y]) {
                obs_left--;
                if(obs_left<0)
                    continue;
            }
            
            if(x==n-1 and y==m-1)
                return steps;
            
            for(int i=0;i<4;i++) {
                int rr = x+dr[i];
                int cc = y+dc[i];
                if(rr<0||cc<0||rr>=n||cc>=m)
                    continue;
                
                if(obs_left > max_obs[rr][cc]) {
                    max_obs[rr][cc] = obs_left;
                    q.push({rr,cc,steps+1,obs_left});
                }
            }
        }
        return -1;
    }
};