// https://leetcode.com/problems/n-queens-ii

class Solution {
private:
    bool valid(vector<vector<int>> &board, int col, int row) {
        int n = board.size();
        for(int cc=col; cc>=0;cc--) {
            if(board[row][cc]) 
                return false;
        }
        for(int i=0; i<=min(row, col);i++) {
            if(board[row-i][col-i])
                return false;
        }
        for(int i=0;i<=min(col, n-row-1);i++) {
            if(board[row+i][col-i])
                return false;
        }
        return true;
    }
    void util(vector<vector<int>> &board, int col, int &cnt) {
        int n = board.size();
        if(col==n) {
            cnt++;
            return;
        }
        for(int row=0;row<n;row++) {
            if(valid(board, col, row)) {
                board[row][col] = 1;
                util(board, col+1, cnt);
                board[row][col] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<vector<int>> board(n, vector<int> (n, 0));
        util(board, 0, cnt);
        return cnt;
    }
};