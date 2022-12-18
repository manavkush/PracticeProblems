// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
private:
    int util(vector<vector<int>> &dp, vector<int> &prices, int canbuy, int idx) {
        int n = prices.size();
        if(idx>=n)
            return 0;
        if(dp[idx][canbuy]!=-1)
            return dp[idx][canbuy];
        int ans = 0;
        if(canbuy) {
            ans = max(util(dp,prices, 1, idx+1), -prices[idx]+util(dp, prices, 0, idx+1));
        } else {
            ans = max(util(dp,prices, 0, idx+1), prices[idx] + util(dp, prices, 1, idx+2));
        }
        return dp[idx][canbuy]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int nextbuy = 0, nextsell = 0;
        int nextnextbuy = 0;
        int currbuy = 0, currsell = 0;
        for(int i=n-1;i>=0;i--) {
            currbuy = max(-prices[i]+nextsell, nextbuy);
            currsell = max(prices[i]+nextnextbuy, nextsell);
            nextnextbuy = nextbuy;
            nextbuy = currbuy;
            nextsell = currsell;
        }
        return nextbuy;
    }
};