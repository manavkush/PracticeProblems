// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int low = prices[0];
        for(int i=0;i<prices.size();i++) {
            if(prices[i]<low)   low = prices[i];
            if(res<prices[i]-low)   res = prices[i]-low;
            // low = min(low, prices[i]);
            // res = max(res, prices[i]-low);
        }
        return res;
    }
};