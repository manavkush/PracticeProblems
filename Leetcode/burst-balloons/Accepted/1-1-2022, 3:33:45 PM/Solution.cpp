// https://leetcode.com/problems/burst-balloons

class Solution {
private:
    int burst(vector<int> &a, int ii, int ff, vector<vector<int>> &dp) {
        if(ii+1==ff)  
            return 0;
        if(dp[ii][ff]>0)    
            return dp[ii][ff];
        
        for(int i=ii+1;i<ff;i++) {
            dp[ii][ff] = max(dp[ii][ff], a[ii]*a[ff]*a[i]+burst(a, ii, i, dp)+burst(a, i, ff, dp));
        }
        return dp[ii][ff];
    }
public:
    int maxCoins(vector<int>& nums) {
        
        vector<int> a;
        a.push_back(1);
        for(auto x: nums) {
            if(x!=0) {
                a.push_back(x);
            }
        }
        a.push_back(1);
        int n = a.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        return burst(a, 0, n-1, dp);
    }
};