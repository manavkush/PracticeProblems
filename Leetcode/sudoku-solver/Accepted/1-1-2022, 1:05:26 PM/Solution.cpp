// https://leetcode.com/problems/sudoku-solver

class Solution {
private: 
    bool canPlace(char val, int row, int col, vector<vector<char>> &board) {
        
        int rr = (row/3)*3;
        int cc = (col/3)*3;

        for(int i=0;i<9;i++) {
            if(board[i][col] == val || board[row][i]==val || board[rr+i%3][cc+i/3] == val ) {
                return false;
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