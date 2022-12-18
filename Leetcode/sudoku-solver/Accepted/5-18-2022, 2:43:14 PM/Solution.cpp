// https://leetcode.com/problems/sudoku-solver

class Solution {
private: 
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
            // cout<<board[row][col]<<" "<<row<<" "<<col<<endl;
            int boxrow = (row/3)*3;
            int boxcol = (col/3)*3;
            
            for(int ival=1;ival<=9;ival++) {
                char val = ('0'+ival);
                
                bool repeat = false; 
                for(int i=0;i<9;i++) {
                    if(board[row][i]==val) {
                        repeat = 1;
                        break;
                    } 
                    if(board[i][col]==val){
                        repeat = 1;
                        break;
                    } 
                    if(board[boxrow+i/3][boxcol+i%3]==val) {
                        repeat = 1;
                        break;
                    }
                }
                if(!repeat) {
                    // cout<<"*";
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