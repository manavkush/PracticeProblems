// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int mod = 1e9+7;
        int n = nums.size();
        long long sum = 0;
        for(auto x: nums) {
            sum+=x;
        }
        if(sum&1) {
            return 0;
        }
        sum /=2;
        long long dp[n+1][sum+1];
        memset(dp, 0, sizeof(dp));
        // Ways to make 0 sum is 1
        for(int i=0;i<=n;i++) {
            dp[i][0] = 1;
        }
        for(long long s=1;s<=sum;s++) {
            for(int i=0;i<n;i++) {
                if(s>=nums[i]) {
                    dp[i+1][s] = (dp[i][s] + dp[i][s-nums[i]])%mod;
                } else {
                    dp[i+1][s] = dp[i][s];
                }
            }
        }
        if(dp[n][sum]) return 1;
        else return 0;
        
    }
};