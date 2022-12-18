// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int> s0(n+1, 0), s1(n+1, 0), s2(n+1, 0);     // profit till ith day when sold the ith
        // s0[0] = 0;
        // s1[0] = -prices[0];
        // s2[0] = INT_MIN;

        int s0, s1, s2;
        s0 = 0;
        s1 = -prices[0];
        s2 = INT_MIN;
        
        for(int i=1;i<n;i++) {
            int news0 = max(s0, s2);
            int news1 = max(s1, s0-prices[i]);
            int news2 = s1+prices[i];
            s0 = news0;
            s1 = news1;
            s2 = news2;
        }
        return max({s0, s2});
    }
};