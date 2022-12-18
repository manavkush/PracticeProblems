// https://leetcode.com/problems/valid-sudoku

class Solution {
private:
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        map<pair<int,char>, int> Rows;
        map<pair<int,char>, int> Cols;
        map<pair<int,char>, int> Boxes;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='.')
                    continue;
                Rows[{i, board[i][j]}]++;
                Cols[{j, board[i][j]}]++;
                Boxes[{(i/3)*3+(j/3), board[i][j]}]++;
            }
        }
        
        for(auto &x: Rows) {
            if(x.second>1) {
                return false;
            }
        }
        for(auto &x: Cols) {
            if(x.second>1) 
                return false;
        }
        for(auto &x: Boxes) {
            if(x.second>1)
                return false;
        }
//         for(int i=0; i<n ;i++) {
//             for(int j=0; j<m; j++) {
//                 bool ans=true;
                
//                 if(board[i][j]=='.')
//                     continue;
                
//                 ans =  checkRow(board, i, j) | checkCol(board, i, j) | checkBox(board, i, j);
//                 if(!ans)
//                     return false;
//             }
//         }
        return true;
    }
};