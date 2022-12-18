// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (3, vector<int> (2, 0)));
        // int dp[n+1][3][2];
        vector<int> nextbuy(k+1, 0);
        vector<int> nextsell(k+1, 0);
        // vector<vector<int>> next(3, vector<int> (2, 0));
        // memset(dp, 0, sizeof(dp));
        
        for(int idx=n-1;idx>=0;idx--) {
            vector<int> currbuy(k+1), currsell(k+1);
            for(int numtrans=1;numtrans<=k;numtrans++) {
                currbuy[numtrans] = max(-prices[idx]+nextsell[numtrans], nextbuy[numtrans]);    // Can buy
                currsell[numtrans] = max(prices[idx]+nextbuy[numtrans-1], nextsell[numtrans]);  // can sell
            }
            nextbuy = currbuy;
            nextsell = currsell;
        }
        return *max_element(nextbuy.begin(), nextbuy.end());
    }
};