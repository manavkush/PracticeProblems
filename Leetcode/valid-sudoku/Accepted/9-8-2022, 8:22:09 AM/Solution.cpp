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

        
        // map<pair<int,char>, int> Rows;
        // map<pair<int,char>, int> Cols;
        // map<pair<int,char>, int> Boxes;
        
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
        // for(auto &x: Rows) {
        //     if(x.second>1) {
        //         return false;
        //     }
        // }
        // for(auto &x: Cols) {
        //     if(x.second>1) 
        //         return false;
        // }
        // for(auto &x: Boxes) {
        //     if(x.second>1)
        //         return false;
        // }
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
        // return true;
    }
};