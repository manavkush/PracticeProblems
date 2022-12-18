// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        // vector<int> dp(n, 0);
        int prev = 0, prevprev = 0;
        
        for(int i=0;i<n;i++) {
            int res = max(prev, prevprev+nums[i]);
            prevprev = prev;
            prev = res;
        }
        return max(prevprev, prev);
    }
};