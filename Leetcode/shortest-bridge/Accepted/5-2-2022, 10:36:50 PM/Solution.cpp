// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int si, sj;
        bool flag = 0;
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    si = i;
                    sj = j;
                    flag = 1;
                    break;
                }
            }
            if(flag) 
                break;
        }
        queue<int> qi, qj;
        qi.push(si); qj.push(sj);
        queue<int> qr, qc;
        
        grid[si][sj] = 2;
        while(!qi.empty()) {
            int ii = qi.front();
            int jj = qj.front();
            qi.pop(); qj.pop();
            qr.push(ii); qc.push(jj);   // global queue(to be used afterwards)
            
            for(int i=0;i<4;i++) {
                int newi = dr[i]+ii;
                int newj = dc[i]+jj;
                if(newj>=0 and newj<n and newi>=0 and newi<n and grid[newi][newj]==1) {
                    qi.push(newi);
                    qj.push(newj);
                    grid[newi][newj] = 2;
                }
            }
        }
        int curr = qr.size();
        int dist = 0;
        while(!qr.empty()) {
            int ii = qr.front();
            int jj = qc.front();
            qr.pop(); qc.pop();
            curr--;
            for(int i=0;i<4;i++) {
                int newi = dr[i]+ii;
                int newj = dc[i]+jj;
                if(newj>=0 and newj<n and newi>=0 and newi<n ) {
                    if(grid[newi][newj]==1) {
                        return dist;
                    } else if(grid[newi][newj]==0) {
                        qr.push(newi);
                        qc.push(newj);
                        grid[newi][newj] = 2;
                    }
                }
            }
            if(curr==0) {
                curr = qr.size();
                dist++;
            }
        }
        return dist;
    }
};