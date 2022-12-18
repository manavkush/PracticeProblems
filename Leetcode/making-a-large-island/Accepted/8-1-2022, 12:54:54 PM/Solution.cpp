// https://leetcode.com/problems/making-a-large-island

class Solution {
private:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    unordered_map<int,int> hs;
    
    int dfs(vector<vector<int>>& grid, int ii, int jj, int color) {
        int cnt = 1;
        
        int n = grid.size();
        grid[ii][jj] = color;
        
        for(int i=0;i<4;i++) {
            int rr = ii + dr[i];
            int cc = jj + dc[i];
            if(rr<0 || cc<0 || rr>=n || cc>=n || grid[rr][cc]!=1)
                continue;
            cnt += dfs(grid, rr, cc, color);
        }
        return cnt;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int color = 2;
        hs[0] = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    hs[color] = dfs(grid, i,j, color);
                    color++;
                }
            }
        }
        int ans = 0;
        for(auto &x: hs) {
            ans = max(ans, x.second);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                
                if(grid[i][j]==0) {
                    int curr = 1;
                    set<int> colors;
                    
                    if(i>0 ) colors.insert(grid[i-1][j]);
                    if(j>0 ) colors.insert(grid[i][j-1]);
                    if(i<n-1 ) colors.insert(grid[i+1][j]);
                    if(j<n-1 ) colors.insert(grid[i][j+1]);
                    
                    for(auto x: colors) {
                        curr += hs[x];
                    }
                    ans = max(ans, curr);
                }
                
            }
        }
        return ans;
    }
};