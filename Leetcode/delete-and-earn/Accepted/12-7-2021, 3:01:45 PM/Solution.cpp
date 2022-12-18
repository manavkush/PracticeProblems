// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hash(20005, 0);
        // unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++) {
            hash[nums[i]]++;
        }
        vector<int> dp(20005, 0);
        
        dp[1] = hash[1];
        int res = hash[1];
        for(int i=2; i<20005;i++) {
            dp[i] = max(dp[i-1], dp[i-2]+i*hash[i]);
            res = max(dp[i], res);
        }
        
        return res;        
    }
};