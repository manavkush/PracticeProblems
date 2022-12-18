// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<int> nextbuy(n+1, 0), nextsell(n+1, 0), currbuy(n+1, 0), currsell(n+1, 0);
        for(int i=n-1;i>=0;i--) {
            currbuy[i] = max(-prices[i] + nextsell[i+1], nextbuy[i+1]);
            currsell[i] = max(prices[i]-fee + nextbuy[i+1], nextsell[i+1]);
            
            nextbuy = currbuy;
            nextsell = currsell;
        }
        return nextbuy[0];
    }
};