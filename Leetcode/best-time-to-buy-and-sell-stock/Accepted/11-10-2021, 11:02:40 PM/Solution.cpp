// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices[0];
        int ans = 0;
        int n = prices.size();
        if(n==1)    return 0;
        
        for(int i=1;i<n;i++) {
            ans = max(prices[i]-prev, ans);
            prev = min(prev, prices[i]);
        }
        return ans;
    }
};