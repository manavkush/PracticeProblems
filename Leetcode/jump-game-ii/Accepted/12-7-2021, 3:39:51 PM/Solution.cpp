// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(11005, 100000);
        dp[0] = 0;
        // for(int i=0;i<n;i++) {
        //     cout<<dp[i]<<" ";
        // }
        for(int i=0;i<n;i++) {
            for(int j=1;j<=nums[i];j++) {
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        // for(int i=0;i<n;i++) {
        //     cout<<dp[i]<<" ";
        // }
        return dp[n-1];
    }
};