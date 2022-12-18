// https://leetcode.com/problems/race-car

class Solution {
private:
    const static int maxDis = 1<<14;
    const int INF = 1e8;
    
    
    int util(int target, vector<int> &dp) {
        if(dp[target]!=-1)
            return dp[target];
        
        dp[target] = INF;
        
        for(int step=0;step<=target;step++) {
            if((1<<step) -1 == target) {
                dp[target] = step;
                break;
            }
            if((1<<step) - 1 > target) {
                dp[target] = min(dp[target], step + 1 + util((1<<step) -1 - target , dp));
                break;
            }
            for(int revstep=0;revstep<step;revstep++) {
                int candidate = step + revstep + 2 + util(target - (1<<step) + (1<<revstep), dp);
                dp[target] = min(dp[target], candidate);
            }
        }
        return dp[target];
    }
public:
    int racecar(int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 0;
        return util(target, dp);
    }
};