// https://leetcode.com/problems/spiral-matrix

class Solution {
private:
    void util(vector<vector<int>> &matrix, vector<int> &ans, int x, int y, int dx, int dy) {
        ans.push_back(matrix[x][y]);
        matrix[x][y] = 101;
        
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int rem = n*m;
        int r = 0, c = 0;
        int lowr = 0, highr = n-1;
        int lowc = 0, highc = m-1;
        while(rem>0) {
            for(int i=lowc;i<=highc and rem;i++) {
                ans.push_back(matrix[lowr][i]);
                rem--;
            }
            lowr++;
            for(int i=lowr;i<=highr and rem;i++) {
                ans.push_back(matrix[i][highc]);
                rem--;
            }
            highc--;
            for(int i=highc;i>=lowc and rem;i--) {
                ans.push_back(matrix[highr][i]);
                rem--;
            }
            highr--;
            for(int i=highr;i>=lowr and rem;i--) {
                ans.push_back(matrix[i][lowc]);
                rem--;
            }
            lowc++;
        }
        return ans;
    }
};