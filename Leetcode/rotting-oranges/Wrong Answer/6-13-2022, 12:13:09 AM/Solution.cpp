// https://leetcode.com/problems/rotting-oranges

class Solution {
private: 
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    bool isValid(vector<vector<int>> &grid, int rr, int cc) {
        if(rr<0 || cc<0 || rr>=grid.size() || cc >=grid[0].size() || grid[rr][cc]!=1) {
            return false;
        }
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> qx, qy;
        
        int m = grid.size();
        int n = grid[0].size();
        
        // initializing a queue
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    qx.push(i);
                    qy.push(j);
                }
            }
        }
        int day = 0;
        int left = qx.size();
        while(!qx.empty()) {
            int r = qx.front();
            int c = qy.front();
            qx.pop();
            qy.pop();
            
            for(int i=0;i<n;i++) {
                int rr = r+dx[i];
                int cc = c+dy[i];
                
                if(isValid(grid, rr, cc)) {
                    grid[rr][cc] = 2;
                    qx.push(rr);
                    qy.push(cc);
                }
            }
            left--;
            if(left==0) {
                if(!qx.empty())
                    day++;
                left = qx.size();
            }
        }
        return day;
    }
};