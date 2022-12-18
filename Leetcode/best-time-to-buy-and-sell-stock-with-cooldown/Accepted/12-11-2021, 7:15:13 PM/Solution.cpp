// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> s0(n+1, 0), s1(n+1, 0), s2(n+1, 0);     // profit till ith day when sold the ith
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        
        for(int i=1;i<n;i++) {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1]-prices[i]);
            s2[i] = s1[i-1]+prices[i];
        }
        return max({s0[n-1], s2[n-1]});
    }
};