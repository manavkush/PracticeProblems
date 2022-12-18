// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
private:
    const int mod = 1e9+7;
    long long util(vector<vector<long long>> &dp, int a, int b) {
        int n = dp.size()-1;
        if(a==n and b==n) return 1;
        if(a>n || b>n) return 0;
        
        if(dp[a][b]!=-1)
            return dp[a][b];
        long long ans = 0;
        
        if(a==b) {
            ans = (util(dp, a+1, b+1)+util(dp,a+2, b+2))%mod;
            ans = (ans + util(dp, a+2, b+1) + util(dp, a+1, b+2))%mod;
        } else if(a-b==1) {
            if(a-b==1)
            ans = (util(dp, a+1, a+1)+util(dp, a, a+1))%mod;
        } else if(b-a==1) {
            ans = (util(dp, b+1, b+1)+util(dp, b+1, b))%mod;
        }
        return dp[a][b] = ans;
    }
public:
    int numTilings(int n) {
        vector<vector<long long>> dp(n+1, vector<long long> (n+1, -1));
        return util(dp, 0, 0);
    }
};