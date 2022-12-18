// https://leetcode.com/problems/maximum-number-of-robots-within-budget

class Solution {

public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int l = 0, r = 0;
        int ans = 0;
        long long runningSum = 0;
        map<int,int, greater<int>> hash;
        for(r=0; r<n;r++) {
            hash[chargeTimes[r]]++;
            runningSum += runningCosts[r];
            
            long long currCost = 0;
            
            int len = hash.size();
            int high = hash.begin()->first;
            currCost = high + runningSum*len;
            
            while(l<=r and currCost>budget) {
                runningSum -= runningCosts[l];
                hash[chargeTimes[l]]--;
                if(chargeTimes[l]==0)
                    hash.erase(chargeTimes[l]);
                l++;
                
                if(!hash.empty()) {
                    len = hash.size();
                    high = hash.begin()->first;
                    currCost = high + runningSum*len;
                } else {
                    currCost = 0;
                }
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};