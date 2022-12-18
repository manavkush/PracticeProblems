// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tot = 0;
        for(int i=0;i<n;i++) {
            tot += gas[i]-cost[i];
        }
        if(tot<0) {
            return -1;
        }
        int start = 0;
        tot = 0;
        for(int i=0;i<n;i++) {
            if(tot<0) {
                start = i;
                tot = 0;
            }
            tot += gas[i]-cost[i];
        }
        return start;
        
    }
};