// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(n==0) {
            if(target>startFuel) return -1;
            else return 0;
        }
        
        vector<vector<int>> dp(n+1, vector<int> (n+1));
        for(int i=0;i<=n;i++) {
            dp[i][0] = startFuel;
        }
        for(int i=0;i<n;i++) {
            for(int t=1;t<=i+1;t++) {
                int taken=0, not_taken = 0;
                not_taken = dp[i][t];
                if(dp[i][t-1]>=stations[i][0]) {
                    taken = dp[i][t-1]+stations[i][1];
                } 
                dp[i+1][t] = max(taken, not_taken);
            }
        }
        
        for(int i=0;i<=n;i++) {
            // cout<<dp[n][i]<<" ";
            if(dp[n][i]>=target) {
                // cout<<endl;
                return i;
            }
        }
        // cout<<endl;
        return -1;
    }
};