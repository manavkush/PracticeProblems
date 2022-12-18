// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<int> s0(n+1, 0);
        // vector<int> s1(n+1, 0);
        
        int s0 = 0;
        int s1 = -prices[0];
        
        for(int i=1;i<n;i++) {
            int temp = max(s0, s1+prices[i]-fee);
            s1 = max(s1, s0-prices[i]);
            s0 = temp;
        }
        return max(s0, s1);
    }
};