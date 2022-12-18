// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        int n = nums.size();
        dp[0] = 1;
        for(int i=1;i<=target;i++) {
            for(int j=0;j<n;j++) {
                int val = nums[j];
                if(val<=i) {
                    dp[i] += dp[i-val];
                }
            }
        }
        return dp[target];
    }
};