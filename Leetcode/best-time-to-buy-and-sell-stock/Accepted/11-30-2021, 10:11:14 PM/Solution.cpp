// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int low = prices[0];
        for(int i=0;i<prices.size();i++) {
            low = min(low, prices[i]);
            res = max(res, prices[i]-low);
        }
        return res;
    }
};