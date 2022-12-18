// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0;i<rows;i++) {
            
            if(matrix[i][0]==0) col0 = 1;
            
            for(int j=1;j<cols;j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=0;i<rows;i++) {
            for(int j=1;j<cols;j++) {
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
            if(col0) matrix[i][0] = 0;
        }
        
        
    }
};