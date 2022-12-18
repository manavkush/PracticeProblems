// https://leetcode.com/problems/n-queens

class Solution {
private: 
    bool canPlace(int rr, int cc, vector<string> &board, int n) {
        int row, col;
        row = rr; col = cc;
        
        while(row>=0 and col>=0) {
            if(board[row][col]=='Q')    return false;
            row--; col--;
        }
        
        row = rr; col = cc;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        col = cc;
        while(row<n and col>=0) {
            if(board[row][col] == 'Q')  return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++) {
            if(canPlace(i, col, board, n)) {
                board[i][col] = 'Q';
                solve(col+1, board, ans, n);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        solve(0, board, ans, n);
        return ans;
    }
};