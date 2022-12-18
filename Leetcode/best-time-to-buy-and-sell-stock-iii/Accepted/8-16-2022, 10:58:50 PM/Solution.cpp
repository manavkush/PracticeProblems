// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
private:
    // int util(vector<vector<vector<int>>> &dp, vector<int> &prices, int idx, int canBuy, int numtrans) {
    //     int n = prices.size();
    //     if(idx==n || numtrans==0)
    //         return 0;
    //     if(dp[numtrans][canBuy][idx]!=-1)
    //         return dp[numtrans][canBuy][idx];
    //     int ans = 0;
    //     if(canBuy) {
    //         ans = max( -prices[idx]+util(dp,prices, idx+1, 0, numtrans), util(dp,prices, idx+1, 1, numtrans));
    //     } else {
    //         ans = max(prices[idx]+util(dp,prices, idx+1, 1, numtrans-1), util(dp,prices, idx+1, 0, numtrans));
    //     }
    //     return dp[numtrans][canBuy][idx] = ans;
    // }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (3, vector<int> (2, 0)));
        // int dp[n+1][3][2];
        vector<vector<int>> next(3, vector<int> (2, 0));
        // memset(dp, 0, sizeof(dp));
        
        for(int idx=n-1;idx>=0;idx--) {
            vector<vector<int>> curr(3, vector<int> (2, 0));
            for(int numtrans=1;numtrans<=2;numtrans++) {
                    curr[numtrans][1] = max(-prices[idx] + next[numtrans][0], next[numtrans][1]);  // CanBuy
                    curr[numtrans][0] = max(prices[idx] + next[numtrans-1][1], next[numtrans][0]); // CanSell
            }
            next = curr;
        }
        return max({next[0][1],next[1][1], next[2][1]});
    }
};