// https://leetcode.com/problems/n-queens

class Solution {
private:
    bool canPlace(vector<string> &curr, int row, int col, int n) {
        int rr = row, cc = col;
        while(rr>=0 and cc>=0) {
            if(curr[rr][cc] == 'Q') return false;
            rr--;
            cc--;
        }
        rr = row, cc = col;
        while(cc>=0) {
            if(curr[rr][cc]=='Q')   return false;
            cc--;
        }
        rr = row, cc = col;
        while(rr<n and cc>=0) {
            if(curr[rr][cc]=='Q') return false;
            rr++;
            cc--;
        }
        return true;
    }
    void util(vector<vector<string>> &ans, vector<string> &curr, int col, int n) {
        if(col == n) {
            ans.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++) {
                        
            if(canPlace(curr, row, col, n)) {
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