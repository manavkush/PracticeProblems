// https://leetcode.com/problems/sudoku-solver

class Solution {
private: 
    bool canPlace(vector<vector<char>> &board, int row, int col, char val) {
        int boxrow = (row/3)*3;
        int boxcol = (col/3)*3;
        for(int i=0;i<9;i++) {
            if(board[row][i]==val || board[i][col]==val || board[boxrow+i/3][boxcol+i%3]==val) {
                return false;
            }
        }
        return true;
    }
    void util(vector<vector<char>> &board, int row, int col, bool &flag)    {
        if(col==9) {
            if(row==8) {
                flag = 1;
                return;
            } else {
                util(board, row+1, 0, flag);
                return;
            }
        }
        
        if(board[row][col]=='.') {
            for(char val='1';val<='9';val++) {
                if(canPlace(board, row, col, val)) {
                    board[row][col] = val;
                    util(board, row, col+1, flag);

                    if(flag)
                        return;
                    board[row][col] = '.';
                }
            }
        } else {
            util(board, row, col+1, flag);
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool flag = 0;
        util(board, 0, 0, flag);
    }
};