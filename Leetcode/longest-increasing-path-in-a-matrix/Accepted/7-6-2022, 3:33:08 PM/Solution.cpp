// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
private:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    int util(vector<vector<int>> &matrix, vector<vector<int>> &vis, int r, int c) {
        if(vis[r][c])
            return vis[r][c];
        
        int n = matrix.size();
        int m = matrix[0].size();
        vis[r][c] = 1;
        
        for(int i=0;i<4;i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(rr<0 || cc<0 || rr>=n || cc>=m || matrix[rr][cc]<= matrix[r][c]) 
                continue;
            vis[r][c] = max(1 + util(matrix, vis, rr, cc), vis[r][c]);
        }
        return vis[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                    ans = max(ans, util(matrix, vis, i,j));
            }
        }
        return ans;
    }
};