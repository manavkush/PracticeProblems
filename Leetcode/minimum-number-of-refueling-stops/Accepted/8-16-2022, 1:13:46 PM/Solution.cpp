// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(n==0) {
            if(target>startFuel) return -1;
            else return 0;
        }
        
        vector<long long> curr(n+1), prev(n+1);
        curr[0] = prev[0] = startFuel;
        
        for(int i=0;i<n;i++) {
            for(int t=1;t<=i+1;t++) {
                long long taken=0, not_taken = 0;
                not_taken = prev[t];
                if(prev[t-1]>=stations[i][0]) {
                    taken = prev[t-1]+stations[i][1];
                }
                curr[t] = max(taken, not_taken);
            }
            prev = curr;
        }
        
        for(int i=0;i<=n;i++) {
            if(curr[i]>=target) {
                return i;
            }
        }
        return -1;
    }
};