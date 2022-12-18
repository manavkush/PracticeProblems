// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> positions(4e5+5);
        for(auto &x: fruits) {
            positions[x[0]+1]+=x[1];
        }
        for(int i=1;i<=2e5+1;i++) {
            positions[i] += positions[i-1];
        }
        int ans = 0;
        for(int r=startPos; r<=min((int)4e5+1, startPos+k);r++) {
            int curr = positions[r+1] -  positions[startPos];
            int disleft = k-2*(r-startPos);
            if(disleft>0) {
                curr += positions[startPos] - positions[startPos-disleft];
            }
            ans = max(ans, curr);
        }
        for(int r=startPos;r>=max(0,startPos-k); r--) {
            int curr = positions[startPos+1]-positions[r];
            int disleft = k-2*(startPos-r);
            if(disleft>0) {
                curr += positions[startPos+1+disleft]-positions[startPos+1];
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};