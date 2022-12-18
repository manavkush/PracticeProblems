// https://leetcode.com/problems/n-queens

class Solution {
private: 
    void util(vector<vector<string>>&ans, vector<string>&curr, vector<int>&rowcheck, vector<int>& updiag, vector<int>& downdiag, int col) {
        int n = curr.size();
        if(col == n) {
            ans.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++) {
            if(rowcheck[row] || downdiag[row+col] || updiag[n-1 + col-row])
                continue;
            rowcheck[row] = downdiag[row+col] = updiag[n-1+col-row] = 1;
            curr[row][col] = 'Q';
            util(ans, curr, rowcheck, updiag, downdiag, col+1);
            curr[row][col] = '.';
            rowcheck[row] = downdiag[row+col] = updiag[n-1+col-row] = 0;

        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr (n, string(n, '.'));
        vector<int> rowcheck(n, 0), updiag(2*n-1, 0), downdiag(2*n-1, 0);
        util(ans, curr, rowcheck, updiag, downdiag, 0);
        return ans;
    }
};