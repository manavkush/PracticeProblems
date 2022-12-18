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
        // Maxdist --> the max distance we can go
        // stops --> number of stops we need to get to the maxdist
        // i -> index of stations that we've covered
        // (stations that are not ahead of maxdist)

        // We'll always take the maximum available fuel 
        // till what we have come. If we cannot add any fuel
        // it means that we're not able to go to the next fuel station
        // Hence -1
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