// https://leetcode.com/problems/snakes-and-ladders

class Solution {

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> vis(n*n, 0);
        vis[0] = 1;
        queue<int> q;
        int dis = 0;
        q.push(0);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                int curr = q.front();
                q.pop();
                
                if(curr==n*n-1)
                    return dis;
                
                for(int j=curr+1;j<min(n*n, curr+6); j++) {
                    if(vis[j])
                        continue;
                    vis[j] = 1;
                    int rr = n - 1 - j/n;
                    int cc;
                    if((n-1-rr)&1) {
                        cc = (n-1) - j%n;
                    } else {
                        cc = j%n;
                    }
                    if(board[rr][cc]==-1) {
                        q.push(j);
                    } else {
                        if(!vis[board[rr][cc]-1]) {
                            q.push(board[rr][cc]-1);
                            vis[board[rr][cc]-1] = 1;                            
                        }
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};