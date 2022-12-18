// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> Buy(n+1, vector<int> (k+2));
        vector<vector<int>> Sell(n+1, vector<int> (k+2));
        
        for(int i=n-1;i>=0;i--) {
            for(int trans=1;trans<=k;trans++) {
                // Buy today OR DON'T BUY TODAY
                Buy[i][trans] = max(-prices[i] + Sell[i+1][trans], Buy[i+1][trans]);
                // Sel Today or Don't sell Today
                Sell[i][trans] = max(prices[i] + Buy[i+1][trans-1], Sell[i+1][trans]);
            }
        }
        return Buy[0][k];
    }
};