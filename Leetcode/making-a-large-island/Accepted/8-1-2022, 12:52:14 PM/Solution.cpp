// https://leetcode.com/problems/making-a-large-island

class Solution {
private:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    unordered_map<int,int> hs;
    
    void bfs(vector<vector<int>>& grid, int ii, int jj, int color) {
        int cnt = 0;
        int n = grid.size();
        
        queue<int> qr, qc;
        qr.push(ii);    qc.push(jj);
        grid[ii][jj] = color;
        
        while(!qr.empty()) {
            int r = qr.front(); qr.pop();
            int c = qc.front(); qc.pop();
            cnt++;
            for(int i=0;i<4;i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(rr<0 || cc<0 || rr>=n || cc>=n || grid[rr][cc]!=1)
                    continue;
                qr.push(rr);
                qc.push(cc);
                grid[rr][cc] = color;
            }
        }
        hs[color] = cnt;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int color = 2;
        hs[0] = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    bfs(grid, i,j, color);
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