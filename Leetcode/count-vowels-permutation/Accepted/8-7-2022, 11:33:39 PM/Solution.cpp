// https://leetcode.com/problems/count-vowels-permutation

class Solution {
private:
    const int mod = 1e9+7;
    long long util(vector<vector<int>> &adj, int n, int prev, vector<vector<int>> &dp) {
        if(n==0)
            return 1;
        if(dp[n][prev]!=-1)
            return dp[n][prev];
        long long ans = 0;
        for(auto &x: adj[prev]) {
            ans = (ans + util(adj, n-1, x, dp))%mod;
        }
        return dp[n][prev] = ans;
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1, vector<int> (5, -1));
        vector<vector<int>> adj(6);
        adj[0] = {1};
        adj[1] = {0,2};
        adj[2] = {0,1,3,4};
        adj[3] = {2,4};
        adj[4] = {0};
        adj[5] = {0, 1, 2, 3, 4};
        long long ans = 0;
        for(int i=0;i<=4;i++) {
            ans = (ans + util(adj, n-1, i, dp))%mod;
        }
        return ans;
    }
};