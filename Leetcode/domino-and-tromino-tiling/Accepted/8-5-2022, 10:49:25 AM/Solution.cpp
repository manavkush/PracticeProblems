// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
private:
    const int mod = 1e9+7;
    long long util(vector<long long> &dp,int n) {
       
        if(dp[n]!=-1)
            return dp[n];
        long long ans = 0;
        ans = (2*util(dp, n-1))%mod;
        ans = (ans + util(dp,n-3))%mod;
        return dp[n] = ans;
    }
public:
    int numTilings(int n) {
        vector<long long> dp(n+2, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        return util(dp, n);
    }
};