// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
private:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> obstac(n, vector<int> (m, -1));
        obstac[0][0] = k;
        
        queue<vector<int>> q;   // r, c, steps, obstac_remaining
        q.push({0, 0, 0, k});
        
        while(!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            int steps = q.front()[2];
            int obs = q.front()[3];
            
            q.pop();
            
            
            if(grid[r][c]==1) {
                obs--;
                if(obs<0) continue; // Can't reach this cell
            }
            
            if(r==n-1 and c==m-1) {  
                return steps;
            }
            
            for(int i=0;i<4;i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(rr<0 || cc<0 || rr>=n || cc>=m )
                    continue;
                if(obstac[rr][cc] < obs) {
                    q.push({rr, cc, steps+1, obs});
                }
            }
        }
        return -1;
    }
};