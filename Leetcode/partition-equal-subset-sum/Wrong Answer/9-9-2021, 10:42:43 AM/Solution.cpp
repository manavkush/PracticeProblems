// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x: nums) {
            sum+=x;
        }
        if(sum&1) {
            return 0;
        }
        sum /=2;
        int dp[sum+1];
        memset(dp, 0, sizeof(dp));
        // Ways to make 0 sum is 1
        dp[0] = 1;
        
        for(int s=1;s<=sum;s++) {
            for(int i=0;i<n;i++) {
                if(s>=nums[i]) {
                    dp[s] = dp[s] | dp[s-nums[i]];
                } else {
                    dp[s] = dp[s];
                }
            }
        }
        return dp[sum];
        
    }
};