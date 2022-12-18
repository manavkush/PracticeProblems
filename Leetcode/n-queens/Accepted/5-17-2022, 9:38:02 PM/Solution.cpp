// https://leetcode.com/problems/n-queens

class Solution {
    void util(vector<vector<string>> &ans, vector<string> &curr, int col, int n) {
        if(col == n) {
            ans.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++) {
            // going top left
            bool flag = true;
            for(int j=0;j<=min(row, col);j++) {
                if(curr[row-j][col-j]=='Q') {
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            
            // going left
            for(int j=0;j<=col;j++) {
                if(curr[row][col-j]=='Q') {
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            // going bottom left
            for(int j=0;j<=min(col, n-1-row);j++) {
                if(curr[row+j][col-j]=='Q') {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                curr[row][col] = 'Q';
                util(ans, curr, col+1, n);
                curr[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        util(ans, curr, 0, n);
        return ans;
    }
};