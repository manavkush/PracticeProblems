// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
private:
    int util(vector<vector<int>> &dp, vector<int> &nums, vector<int> &multipliers, int i, int f) {
        int n = nums.size();
        int m = multipliers.size();
        
        int used = i+(n-1-f);
        if(used >= multipliers.size())
            return 0;
        
        if(dp[i][n-1-f]!=-1)
            return dp[i][n-1-f];
        
        int ans1 = multipliers[used]*nums[i] + util(dp, nums, multipliers, i+1, f);
        int ans2 = multipliers[used]*nums[f] + util(dp, nums, multipliers, i, f-1);
        
        return dp[i][n-1-f] = max(ans1, ans2);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m+1, vector<int> (m+1, -1));
        
        return util(dp, nums, multipliers, 0, nums.size()-1);
    }
};