// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<int> qx, qy;
        set<pair<int,int>> st;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    qx.push(i);
                    qy.push(j);
                }
            }
        }
        int time = 0;
        int curr = qx.size();
        
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        
        while(!qx.empty()) {
            int r = qx.front();
            int c = qy.front();
            
            qx.pop();
            qy.pop();
            curr--;
            
            for(int i=0;i<4;i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(rr<0 || cc<0 || rr>=n || cc>=m) {
                    continue;
                } else if(grid[rr][cc]==1) {
                    qx.push(rr);
                    qy.push(cc);
                    grid[rr][cc] = 2;
                }
            }
            if(curr==0) {
                time++;
                curr = qx.size();
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return time-1;
    }
};