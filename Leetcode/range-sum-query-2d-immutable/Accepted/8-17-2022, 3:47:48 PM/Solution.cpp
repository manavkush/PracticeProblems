// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
private:
    vector<vector<int>> pref;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        pref.assign(n+1, vector<int> (m+1, 0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                pref[i+1][j+1] = pref[i][j+1]+pref[i+1][j] - pref[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans = pref[r2+1][c2+1]-pref[r2+1][c1]-pref[r1][c2+1]+pref[r1][c1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */