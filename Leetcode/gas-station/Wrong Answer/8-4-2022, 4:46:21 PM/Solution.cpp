// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++) {
            diff[i] = gas[i]-cost[i];
        }
        int sum = 0;
        accumulate(diff.begin(), diff.end(), sum);
        if(sum<0) {
            return -1;
        }
        vector<int> pref(n), suff(n);
        int start = 0;
        sum = 0;
        for(int i=0;i<n;i++) {
            if(sum<0) {
                start = i;
                sum = 0;
            }
            sum += diff[i];
        }
        return start;
        
    }
};