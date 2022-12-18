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
        vector<int> nextbuy(n+2, 0), nextsell(n+2, 0);
        vector<int> currbuy(n+2, 0), currsell(n+2, 0);
        for(int i=n-1;i>=0;i--) {
            currbuy[i] = max(-prices[i]+nextsell[i+1], currbuy[i+1]);
            currsell[i] = max(prices[i]+nextbuy[i+2], currsell[i+1]);
            
            nextbuy = currbuy;
            nextsell = currsell;
        }
        return nextbuy[0];
    }
};