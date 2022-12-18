// https://leetcode.com/problems/stone-game-ii

class Solution {
private:
    int dp[100][201][2];  // index, m, turn
    const int INF = 1e8;
    int util(vector<int> &piles, vector<int> &pref, int idx, int m, int turn) {
        int n = piles.size();
        if(idx==n) {
            return 0;
        }
        if(dp[idx][m][turn]!=-1) {
            return dp[idx][m][turn];
        }
        int ans = 0;
        if(!turn) {
            for(int i=idx;i<min(n, idx+2*m);i++) {
                ans = max(ans, pref[i+1]-pref[idx] + util(piles, pref, i+1, max(m, (i-idx+1)), turn^1 ));
            }
        } else {
            ans = INF;
            for(int i=idx;i<min(n, idx+2*m);i++) {
                ans = min(ans, util(piles, pref, i+1, max(m, (i-idx+1)), turn^1));
            }
        }
        return dp[idx][m][turn] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        vector<int> pref(n+1);
        
        for(int i=0;i<n;i++) {
            pref[i+1] = pref[i] + piles[i];
        }
        return util(piles, pref, 0, 1, 0);
    }
};