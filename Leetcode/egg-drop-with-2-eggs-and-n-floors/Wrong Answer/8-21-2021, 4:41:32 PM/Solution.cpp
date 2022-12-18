// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors

class Solution {
public:
    int dp[1001] = {0};
    int twoEggDrop(int n) {
        
        for(int i=1;i<=n;i++) {
            if(dp[i]==0) {
                dp[n] = min(dp[n]==0 ? n : dp[n], 1 + max(twoEggDrop(i-1), twoEggDrop(n-i)));
            }
        }
        return dp[n];
        
    }
};