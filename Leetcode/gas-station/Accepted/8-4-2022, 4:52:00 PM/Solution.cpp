// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        int tot = 0;
        for(int i=0;i<n;i++) {
            diff[i] = gas[i]-cost[i];
            tot += diff[i];
        }
        // cout<<tot<<endl;
        if(tot<0) {
            return -1;
        }
        vector<int> pref(n), suff(n);
        int start = 0;
        tot = 0;
        for(int i=0;i<n;i++) {
            if(tot<0) {
                start = i;
                tot = 0;
            }
            tot += diff[i];
        }
        return start;
        
    }
};