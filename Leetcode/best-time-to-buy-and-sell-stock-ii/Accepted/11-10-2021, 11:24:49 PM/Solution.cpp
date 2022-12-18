// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int curr = INT_MAX;
        bool tr = 0;
        for(int i=0;i<n-1;i++) {
            
            if(a[i]>a[i+1]) {
                if(!tr) {
                    curr = a[i+1];
                } else {
                    ans += a[i] - curr;
                    curr = a[i];
                    tr = 0;
                }
            } else {
                curr = min(a[i], curr);
                tr = 1;
            }
        }
        if(tr) {
            ans += a[n-1] - curr;
        }
        return ans;
    }
};