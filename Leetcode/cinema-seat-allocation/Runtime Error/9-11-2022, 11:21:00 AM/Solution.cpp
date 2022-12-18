// https://leetcode.com/problems/cinema-seat-allocation

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>> grid(n+1, vector<int> (10+1));
        for(auto &x: reservedSeats) {
            int r = x[0];
            int c = x[1];
            r--, c--;
            grid[r][c]=1;
        }
        for(int row = 0; row<n; row++) {
            for(int i=1;i<10;i++) {
                grid[row][i] += grid[row][i-1];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(grid[i][8]==grid[i][0]) {
                ans += 2;
                continue;
            }
            if((grid[i][0]==grid[i][4]) || (grid[i][2]==grid[i][6]) || (grid[i][4]==grid[i][8]))  {
                ans++;
            }
        }
        return ans;
    }
};