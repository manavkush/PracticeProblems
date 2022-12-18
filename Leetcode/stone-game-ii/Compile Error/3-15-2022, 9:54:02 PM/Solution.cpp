// https://leetcode.com/problems/stone-game-ii

class Solution {
private: 
    int rec(vector<int> &piles, int curn, int curm, int turn) {
        int n = piles.size();
        if(curn>=n) {
            return 0;
        } 
        if(vis[curn][curm][turn]!=-1) {
            return vis[curn][curm][turn];
        }
        for(int i=0;i<n;i++) {
            
        }
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int m = 1;
        int ans = 0;
        ans = max(rec(piles, 1, 1, 0), rec(piles,1, 2, 0));
    }
};