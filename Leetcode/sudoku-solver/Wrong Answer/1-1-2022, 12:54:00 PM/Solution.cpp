// https://leetcode.com/problems/sudoku-solver

class Solution {
private: 
    bool canPlace(char val, int row, int col, vector<vector<char>> &board) {
        int rr = row, cc = col;
        for(int i=0;i<9;i++) {
            if(board[i][col] == val) {
                return false;
            }
            if(board[row][i] == val) {
                return false;
            }
        }
        rr = (row/3)*3;
        cc = (col/3)*3;
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                if(board[rr+i][cc+j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>&board) {

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                    for(char val = '1'; val<='9';val++) {
                        if(canPlace(val, i, j, board)) {
                            board[i][j] = val;
                            if(solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';                            
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); 
    }
};