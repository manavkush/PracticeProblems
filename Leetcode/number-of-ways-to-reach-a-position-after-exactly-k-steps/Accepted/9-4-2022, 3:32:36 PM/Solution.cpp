// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps

class Solution {
private:
    const long long mod = 1e9+7;
    long long calc(int n, int r, vector<vector<long long>> &dp) {
        if(r==0 || n==r)
            return 1;
        if(dp[n][r]!=-1)
            return dp[n][r];
        long long ans = (calc(n-1, r, dp) + calc(n-1, r-1, dp))%mod;
        return dp[n][r] = ans;
    }  
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(startPos-endPos);
        
        if( (diff>k) || ((k-diff)&1) ) {
            return 0;
        } 
        int n = (k+diff)/2;
        int m = (k-diff)/2;
        
        vector<vector<long long>> dp(n+m+1, vector<long long> (m+1, -1));
        return calc(n+m, m, dp);
    }
};