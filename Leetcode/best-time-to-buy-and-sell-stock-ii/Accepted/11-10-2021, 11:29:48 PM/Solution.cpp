// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int curr = a[0];
        for(int i=1;i<n;i++) {
            if(a[i]>curr) {
                ans += a[i] - curr;
                curr = a[i];
            } else {
                curr = a[i];
            }
        }
        return ans;
    }
};