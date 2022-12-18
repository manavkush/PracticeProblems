// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        long long ans = 0;
        
        for(int i=0;i<n;) {
            long long sum = neededTime[i];
            int high = neededTime[i];
            int j = i+1;
            
            for(;j<n;j++) {
                if(colors[j]!=colors[i])
                    break;
                
                high = max(high, neededTime[j]);
                sum += neededTime[j];
            }
            
            ans += sum - high;
            i = j;
        }
        return ans;
    }
};