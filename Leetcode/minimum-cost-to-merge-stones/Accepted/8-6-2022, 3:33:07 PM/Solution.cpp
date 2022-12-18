// https://leetcode.com/problems/minimum-cost-to-merge-stones

class Solution {
private:
    const int INF = 1e8;
    int k;
    int util(vector<vector<vector<int>>> &dp, vector<int> &stones, vector<int> &pref, int i, int f, int piles) {
        // cout<<i<<" "<<f<<" "<<piles<<endl;
        
        if(piles==f-i+1) {
            return 0;
        } 
        if(piles>f-i+1) {
            return INF;
        }
        if(dp[i][f][piles]!=-1)
            return dp[i][f][piles];
        
        if(piles==1) {
            return dp[i][f][1] = min(INF,util(dp,stones,pref,i, f, k) + pref[f+1]-pref[i]);
        }
        
        int curr = INF;
        for(int mid=i+1;mid<=f;mid++) {
            curr=min(curr, util(dp,stones,pref,i,mid-1,1)+util(dp, stones, pref, mid, f, piles-1));
        }
        return dp[i][f][piles] = curr;
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        
        if(n==1)
            return 0;
        vector<int> pref(n+1, 0);
        for(int i=0;i<n;i++) {
            pref[i+1] = pref[i] + stones[i];
        }
        this->k = k;
        // dp[i][j][k] = min cost to merge i...j into k piles
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (k+1, -1)));
        // INITIALIZE
        for(int i=0;i<n;i++) {
            dp[i][i][1] = 0;
            for(int j=2;j<=k;j++) {
                dp[i][i][j] = INF;
            }
        }
        int ans = util(dp, stones, pref, 0, n-1, 1);
        return (ans == INF ? -1 : ans);
    }
};