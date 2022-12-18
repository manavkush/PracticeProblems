// https://leetcode.com/problems/surrounded-regions

class Solution {
private: 
    void bfs(vector<vector<char>> &board, int x, int y) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        queue<int> qx,qy;
        qx.push(x); qy.push(y);
        int m = board.size();
        int n = board[0].size();
        board[x][y] = '*';
        while(!qx.empty()) {
            int xx = qx.front();
            int yy = qy.front();
            qx.pop(); qy.pop();
            for(int i=0;i<4;i++) {
                int newx = xx + dx[i];
                int newy = yy + dy[i];
                if(newx<m and newy<n and newx>=0 and newy>=0 and board[newx][newy]=='O') {
                    board[newx][newy] = '*';
                    qx.push(newx);
                    qy.push(newy);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++) {
            if(board[i][0]=='O')
                bfs(board, i, 0);
            if(board[i][n-1]=='O')
                bfs(board, i, n-1);
        }
        for(int i=0;i<n;i++) {
            if(board[0][i]=='O') {
                bfs(board,0,i);
            }
            if(board[m-1][i]=='O') {
                bfs(board, m-1, i);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='O') {
                    board[i][j] = 'X';
                } else if(board[i][j]=='*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};