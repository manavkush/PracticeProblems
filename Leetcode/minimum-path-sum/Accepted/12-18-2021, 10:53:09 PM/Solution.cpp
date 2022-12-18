// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=m-2;i>=0;i--) {
            grid[n-1][i] += grid[n-1][i+1];
        }
        
        for(int i=n-2;i>=0;i--) {
            grid[i][m-1] += grid[i+1][m-1];
        }
        
        for(int i=n-2; i>=0;i--) {
            for(int j=m-2;j>=0;j--) {
                grid[i][j] = min(grid[i][j+1], grid[i+1][j]) + grid[i][j];
            }
        }
        return grid[0][0];
    }
};