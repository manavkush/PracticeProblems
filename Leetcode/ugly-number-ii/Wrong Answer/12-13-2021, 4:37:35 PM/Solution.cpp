// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1000000);
        dp[1] = 1;
        
        for(int i=0;i<1000000;i++) {
            if(dp[i]==1) {
                if(i*2<1000000) {
                    dp[2*i] = 1;
                } 
                if(i*3<1000000) {
                    dp[3*i] = 1;
                }
                if(i*5 < 1000000) {
                    dp[5*i] = 1;
                }
            }
        }
        int count = 0;
        int i = 0;
        for(i=1;i<1000000;i++) {
            count += dp[i];
            if(count==n)    break;
        }
        return i;
    }
};