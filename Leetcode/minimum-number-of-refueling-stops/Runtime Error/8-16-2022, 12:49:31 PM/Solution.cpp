// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(n==0) {
            if(target>startFuel) return -1;
            else return 0;
        }
        // dp[0] = startFuel;
        vector<vector<int>> dp(n+1, vector<int> (n+1));
        for(int i=0;i<n;i++) {
            dp[i][0] = startFuel;
        }
        for(int i=0;i<n;i++) {
            for(int t=1;t<=i;t++) {
                if(dp[i][t-1]>=stations[i][0]) {
                    int not_taken = dp[i][t];
                    int taken = dp[i][t-1]+stations[i][1];
                    dp[i+1][t] = max(taken, not_taken);
                } else {
                    break;
                }
            }
        }
        
        for(int i=0;i<=n;i++) {
            if(dp[n+1][i]>=target) {
                return i;
            }
        }
        return -1;
    }
};