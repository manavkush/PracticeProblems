// https://leetcode.com/problems/flood-fill

class Solution {
private:
    vector<int> dr;
    vector<int> dc;
    bool valid(int rr, int cc, int n, int m) {
        if(rr<0 || cc<0 || rr>=n || cc>=m) {
            return false;
        } return true;
    }
public:
    Solution() {
        dr = {0, 0, 1,-1};
        dc = {1, -1, 0, 0};
    }
    void floodUtil(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int col = image[sr][sc];
        image[sr][sc] = newColor;
        for(int i=0;i<4;i++) {
            int rr = sr + dr[i];
            int cc = sc + dc[i];
            if(valid(rr, cc, image.size(), image[0].size()) and image[rr][cc]==col) {
                floodUtil(image, rr, cc, newColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        floodUtil(image, sr, sc, newColor);
        return image;
    }

};