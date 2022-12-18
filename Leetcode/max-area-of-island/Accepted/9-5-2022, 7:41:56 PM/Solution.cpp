// https://leetcode.com/problems/max-area-of-island

class Solution {
private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int n, m;
    int dfs(vector<vector<int>> &grid, int x, int y) {
        int ans = 1;
        grid[x][y] = 2;
        for(int i=0;i<4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx<0 || yy<0 || xx>=n || yy>=m|| grid[xx][yy]!=1) 
                continue;
            ans += dfs(grid, xx, yy);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        
        return ans;
    }
};