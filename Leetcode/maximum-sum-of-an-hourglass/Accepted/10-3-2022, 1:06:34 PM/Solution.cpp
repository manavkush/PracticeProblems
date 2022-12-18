// https://leetcode.com/problems/maximum-sum-of-an-hourglass

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<long long>> pref(n+1, vector<long long> (m+1, 0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                pref[i+1][j+1] = grid[i][j] + (pref[i+1][j] + pref[i][j+1] - pref[i][j]);
            }
        }
        long long ans = 0;
        
        for(int i=3;i<=n;i++) {
            for(int j=3;j<=m;j++) {
                long long curr = pref[i][j] - pref[i-3][j] - pref[i][j-3] + pref[i-3][j-3] - grid[i-2][j-1] - grid[i-2][j-3];
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};