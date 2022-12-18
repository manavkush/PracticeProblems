// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum = 0;
        int curr = 0;
        for(int i=1;i<n;i++) {
            while(i<n and prices[i]>=prices[i-1]) {
                i++;
            }
            
            if(i==n) {
                sum+=prices[n-1]-prices[curr];
                return sum;
            } else {
                sum+=prices[i-1]-prices[curr];
                curr = i;
            }
        }
        return sum;
    }
};