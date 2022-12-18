// https://leetcode.com/problems/number-of-islands

class Solution {
private:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
    void dfs(vector<vector<char>> &grid, int r, int c) {
        grid[r][c] = '*';
        for(int i=0;i<4;i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(rr<0 || cc<0 || rr>=grid.size() || cc >= grid[0].size() || grid[rr][cc]!='1')
                continue;
            dfs(grid, rr, cc);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    dfs(grid, i, j);
                    cnt++;                        
                }
            }
        }
        return cnt;
    }
};