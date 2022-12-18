// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 1005));
        dp[1][1] = 0;
        dp[2][1] = 2;
        
        for(int i=3;i<=n;i++) {
            // Elements
            for(int copy = 1;copy<=i; copy++) {
                dp[i][copy] = min(dp[i][copy], dp[i-copy][copy] + 1);
                dp[i][i] = min(dp[i][i], dp[i][copy]+1);
            }          
        }
        int ans = 1005;
        for(int i=1;i<=n;i++) {
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }
};