// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
private:
    int util(vector<vector<vector<int>>> &dp, vector<int> &prices, int idx, int canBuy, int numtrans) {
        int n = prices.size();
        if(idx==n || numtrans==2)
            return 0;
        if(dp[numtrans][canBuy][idx]!=-1)
            return dp[numtrans][canBuy][idx];
        int ans = 0;
        if(canBuy) {
            ans = max( -prices[idx]+util(dp,prices, idx+1, 0, numtrans), util(dp,prices, idx+1, 1, numtrans));
        } else {
            ans = max(prices[idx]+util(dp,prices, idx+1, 1, numtrans+1), util(dp,prices, idx+1, 0, numtrans));
        }
        return dp[numtrans][canBuy][idx] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (2, vector<int> (n, -1)));
        // memset(dp, -1, sizeof(dp));
        return util(dp, prices, 0, 1, 0);
    }
};