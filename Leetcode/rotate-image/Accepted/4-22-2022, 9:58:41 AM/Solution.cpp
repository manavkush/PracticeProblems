// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tracks = n/2;
        for(int i=0;i<tracks;i++) {
            for(int j=i;j<n-i-1;j++) {
                int val = matrix[i][j];
                int xx = i;
                int yy = j;
                for(int cnt = 0; cnt<4; cnt++) {
                    int tmp = yy;
                    yy = n-1 -xx;
                    xx = tmp;
                    swap(val, matrix[xx][yy]);
                }                
            }
        }
    }
};