// https://leetcode.com/problems/race-car

class Solution {
private:
    const static int maxDis = 1<<14;
    const int INF = 1e8;
    // map<vector<int>, int> dp;
    int dp[(maxDis*2)+5][16][2];
    
    int util(int node, int speedPow, int dir, int steps, int target) {
        if(node>maxDis || node<=-maxDis || steps>target) {
            return INF;
        }
        if(dp[node+maxDis][speedPow][dir]!=-1)
            return dp[node+maxDis][speedPow][dir] = dp[node+maxDis][speedPow][dir];
        
        if(node==target) {
            return dp[node+maxDis][speedPow][dir] = steps;
        }
        
        dp[node+maxDis][speedPow][dir] = INF;
        
        int speed;
        
        if(dir) {
            speed = -(1<<speedPow);
        } else {
            speed = (1<<speedPow);
        }
        // A
        int ans1 = util(node+speed, speedPow+1, dir, steps+1, target);
        // R
        int ans2 = util(node, 0, dir^1, steps+1, target);
        
        return dp[node+maxDis][speedPow][dir] = min({dp[node+maxDis][speedPow][dir], ans1, ans2});
    }
public:
    int racecar(int target) {
        memset(dp, -1, sizeof(dp));
        return util(0, 0, 0, 0, target);
    }
};