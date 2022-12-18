// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<long long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<=amount;i++) {
            if(dp[i]!=INT_MAX) {
                for(int j=0;j<n;j++) {
                    if(i+coins[j] <= amount) 
                        dp[i + coins[j]] = min(dp[i] + 1, dp[i+coins[j]]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};