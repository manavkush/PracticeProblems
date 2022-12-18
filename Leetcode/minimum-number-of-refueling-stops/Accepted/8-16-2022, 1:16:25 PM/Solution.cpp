// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(n==0) {
            if(target>startFuel) return -1;
            else return 0;
        }
        
        vector<long long> max_dist(n+1);
        max_dist[0] = startFuel;
        for(int i=0;i<n;i++) {
            for(int t=i+1;t>=1;t--) {
                long long taken=0, not_taken = 0;
                
                not_taken = max_dist[t];
                
                if(max_dist[t-1]>=stations[i][0]) {
                    taken = max_dist[t-1]+stations[i][1];
                }
                max_dist[t] = max(taken, not_taken);
            }
        }
        
        for(int i=0;i<=n;i++) {
            if(max_dist[i]>=target) {
                return i;
            }
        }
        return -1;
    }
};