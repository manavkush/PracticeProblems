// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        map<pair<int,int>,int> done;
        queue<int> qc,qr;
        qc.push(sc); qr.push(sr);
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        int og = image[sr][sc];
        while(!qc.empty()) {
            int c = qc.front(); qc.pop();
            int r = qr.front(); qr.pop();
            
            for(int i=0;i<4;i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(rr<0 || cc<0 || rr>=n || cc>=m || image[rr][cc]!=og) {
                    continue;
                }
                image[rr][cc] = color;
                qr.push(rr); qc.push(cc);
            }
        }
        return image;
    }
};