// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int high = 0;
        
        for(int i=0;i<n;i++) {
            if(high<i) break;
            high = max(high, i+nums[i]);
        }
        if(high>=n-1) {
            return 1;
        } else {
            return 0;
        }
    }
};