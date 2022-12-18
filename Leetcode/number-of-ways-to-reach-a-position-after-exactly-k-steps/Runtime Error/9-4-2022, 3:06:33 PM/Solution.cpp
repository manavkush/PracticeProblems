// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        const int mod = 1e9+7;
        int diff = abs(startPos-endPos);
        
        if( (diff>k) || ((k-diff)&1) ) {
            return 0;
        } 
        int n = (k+diff)/2;
        int m = (k-diff)/2;
        
        long long ans = 1;
        for(int i=1;i<=m;i++) {
            ans = ((ans * (n+m-i+1))/i);
        }
        return ans%mod;
    }
};