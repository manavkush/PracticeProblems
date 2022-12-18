// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int minSteps(int n) {
        vector<vector<long long>> dp(n+1, vector<long long> (2*n+1, INT_MAX));
        dp[1][1] = 0;
        dp[2][1] = 2;
        
        for(int i=3;i<=n;i++) {
            cout<<i<<" : ";
            for(int copy = 1;copy<i; copy*=2) {
                dp[i][copy] = min(dp[i][copy], dp[i-copy][copy] + 1);
                dp[i][copy*2] = min(dp[i][copy*2], dp[i][copy]+1);
                // if(copy>1)
                //     dp[i][copy] = min(dp[i][copy], dp[i-copy][copy/2]+2);
                cout<<dp[i][copy]<<" ";
            }
            cout<<endl;            
        }
        long long ans = INT_MAX;
        for(int i=1;i<=n;i++) {
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }
};