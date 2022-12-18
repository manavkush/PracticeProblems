// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(10005);
        
        for(int i=0;i<n;i++) {
            hash[nums[i]]++;
        }
        vector<int> dp(10005, 0);
        dp[1] = hash[1];
        for(int i=2;i<=10000;i++) {
            dp[i] = max(dp[i-1], dp[i-2]+hash[i]*i);
        }
        return dp[10000];
    }
};