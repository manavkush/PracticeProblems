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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (3, vector<int> (2, 0)));
        
        for(int idx=n-1;idx>=0;idx--) {
            for(int numtrans=1;numtrans>=0;numtrans--) {
                    dp[idx][numtrans][1] = max(-prices[idx] + dp[idx+1][numtrans][0], dp[idx+1][numtrans][1]);  // CanBuy
                    dp[idx][numtrans][0] = max(prices[idx] + dp[idx+1][numtrans+1][1], dp[idx+1][numtrans][0]); // CanSell
            }
        }
        return max({dp[0][0][1],dp[0][1][1], dp[0][2][1]});
    }
};