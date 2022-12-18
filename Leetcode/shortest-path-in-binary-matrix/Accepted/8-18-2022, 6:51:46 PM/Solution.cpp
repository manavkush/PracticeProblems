// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dr = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dc = {1, -1, 0, 0, 1, -1, 1, -1};
        queue<int> qr, qc;
        if(grid[0][0]==1)
            return -1;
        if(n==1 and m==1)
            return 1;
        grid[0][0] = 2;
        qr.push(0); qc.push(0);
        int dis = 1;
        while(!qr.empty()) {
            int sz = qr.size();
            while(sz--) {
                int r = qr.front(); qr.pop();
                int c = qc.front(); qc.pop();

                for(int i=0;i<8;i++) {
                    int rr = r + dr[i];
                    int cc = c + dc[i];

                    if(rr<0 || cc<0 || rr>=n || cc>=m || grid[rr][cc]!=0) {
                        continue;
                    }
                    qr.push(rr);
                    qc.push(cc);
                    grid[rr][cc] = 2;
                    if(rr==n-1 and cc==m-1)
                        return dis+1;
                }
            }
            dis++;
        }
        return -1;
    }
};