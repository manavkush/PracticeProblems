// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 10005);
        dp[0] = 0;
        
        for(int i=1;i<=amount;i++) {
            for(int j=0;j<n;j++) {
                if(i>=coins[j]) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]==10005 ? -1 : dp[amount];
        
    }
};