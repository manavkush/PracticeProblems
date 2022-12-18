// https://leetcode.com/problems/combination-sum-iv

class Solution {
private:
    int util(vector<int> &dp, vector<int> &nums, int target) {
        if(target<0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            ans += util(dp, nums, target-nums[i]);
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 1;
        return util(dp, nums, target);
    }
};