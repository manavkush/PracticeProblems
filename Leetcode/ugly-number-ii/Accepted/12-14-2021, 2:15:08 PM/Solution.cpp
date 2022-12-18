// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int t1, t2, t3;
        t1 = t2 = t3 = 0;
        
        for(int i=1;i<n;i++) {
            dp[i] = min({dp[t1]*2, dp[t2]*3, dp[t3]*5});
            if(dp[i] == dp[t1]*2)   t1++;
            if(dp[i] == dp[t2]*3)   t2++;
            if(dp[i] == dp[t3]*5)   t3++;
        }        
        return dp[n-1];
    }
};