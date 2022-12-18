// https://leetcode.com/problems/valid-sudoku

class Solution {
private:
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> Rows(9, vector<int> (10, 0));
        vector<vector<int>> Cols(9, vector<int> (10, 0));
        vector<vector<int>> Boxes(9, vector<int> (10, 0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='.')
                    continue;
                
                int ch = board[i][j]-'0';
                Rows[i][ch]++;
                Cols[j][ch]++;
                Boxes[(i/3)*3+(j/3)][ch]++;
            }
        }
        for(int i=0;i<9;i++) {
            for(int j=1;j<=9;j++) {
                if(Rows[i][j]>1 || Cols[i][j]>1 || Boxes[i][j]>1)
                    return false;
            }
        }
        return true;
    }
};