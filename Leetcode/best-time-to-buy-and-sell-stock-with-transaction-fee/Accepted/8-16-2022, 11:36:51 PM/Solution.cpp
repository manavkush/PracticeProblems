// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int nextbuy=0, nextsell=0, currbuy=0, currsell=0;
        for(int i=n-1;i>=0;i--) {
            currbuy = max(-prices[i] + nextsell, nextbuy);
            currsell = max(prices[i]-fee + nextbuy, nextsell);
            
            nextbuy = currbuy;
            nextsell = currsell;
        }
        return nextbuy;
    }
};