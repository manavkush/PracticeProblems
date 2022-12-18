// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(n==0) {
            if(target>startFuel) return -1;
            else return 0;
        }
        priority_queue<int> pq; // dist, refuels
        int stops = 0, maxdist = startFuel, i=0;
        
        while(maxdist<target) {
            for(;i<n and stations[i][0]<=maxdist;i++) {
                pq.push(stations[i][1]);
            }
            if(pq.empty()) return -1;
            int top = pq.top(); pq.pop();
            maxdist += top;
            stops++;
        }
        return stops;
        
    }
};