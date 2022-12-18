// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> vec;
        unordered_map<int,priority_queue<int>> hash;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                hash[i-j].push(-mat[i][j]);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                mat[i][j] = -hash[i-j].top();
                hash[i-j].pop();
            }
        }
        return mat;
    }
};