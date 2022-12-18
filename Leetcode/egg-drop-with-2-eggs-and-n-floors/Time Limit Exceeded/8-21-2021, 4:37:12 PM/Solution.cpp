// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors

class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n+1,0);  // Stores the min. no of moves needed to determine f from a floor
        for(int i=1;i<=n;i++) {
            if(dp[i]==0) {
                dp[n] = min(dp[n]==0 ? n : dp[n], 1 + max(twoEggDrop(i-1), twoEggDrop(n-i)));
            }
        }
        return dp[n];
        
    }
};