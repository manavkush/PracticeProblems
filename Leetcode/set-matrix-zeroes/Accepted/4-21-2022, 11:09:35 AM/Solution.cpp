// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // store if zero or not in the header
        int m = matrix.size();
        int n = matrix[0].size();
        bool col1 = false;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0) {
                    if(j==0) {
                        col1 = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                    matrix[i][0] = 0;
                }
            }
        }
        for(int col=1;col<n;col++) {
            if(matrix[0][col]==0) {
                for(int row=1;row<m; row++) {
                    matrix[row][col] = 0;
                }
            }
        }
        for(int row = 0; row<m;row++) {
            if(matrix[row][0]==0) {
                for(int col=1;col<n;col++) {
                    matrix[row][col] = 0;
                }
            }
        }
        if(col1) {
            for(int row = 0; row<m;row++) {
                matrix[row][0] = 0;
            }
        }
    }
};