// https://leetcode.com/problems/best-team-with-no-conflicts

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++) {
            res.push_back({scores[i], ages[i]});
        }
        sort(res.begin(), res.end());
        
        int dp[n+1];
        memset(dp, 0, sizeof(dp));  // Maximum sum till this index
        
        for(int i=0;i<n;i++) {
            dp[i] = res[i].first;
            for(int j=0;j<i;j++) {
                if(res[i].second>=res[j].second) {
                    dp[i] = max(dp[i], dp[j]+res[i].first);
                }
            }
        }
        int curr = 0;
        for(int i=0;i<n;i++) {
            curr = max(dp[i], curr);
        }
        return curr;
        
    }
};