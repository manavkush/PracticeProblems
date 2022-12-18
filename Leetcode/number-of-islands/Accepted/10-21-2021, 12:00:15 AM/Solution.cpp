// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        int m = grid.size();
        int n = grid[0].size();
        queue<int> qr, qc;
        int vis[m][n];
        for(int i=0;i<m;i++) for(int j=0;j<n; j++)  vis[i][j] = 0;
        int count = 0;
        for(int i=0;i<m;i++) {
            for(int j=0; j<n; j++) {
                
                if(grid[i][j]=='1' and (!vis[i][j])) {
                    // for(int i=0;i<m;i++) {
                    //     for(int j =0 ;j<n;j++) {
                    //         cout<<vis[i][j]<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                    // cout<<endl;
                    count ++;
                    qr.push(i);
                    qc.push(j);
                    vis[i][j] = 1;
                    while(!qr.empty()) {
                        int r = qr.front();
                        int c = qc.front();
                        qr.pop(); qc.pop();
                        for(int it=0;it<4;it++) {
                            int rr = r + dr[it];
                            int cc = c + dc[it];
                            if(rr<0 || cc<0 || rr>=m || cc>=n) {
                                continue;
                            }
                            if(grid[rr][cc]=='0' || vis[rr][cc]) {
                                continue;
                            }
                            vis[rr][cc] = 1;
                            qr.push(rr);
                            qc.push(cc);
                        }
                    }
                }
            }
        }
        
        return count;
        
    }
};