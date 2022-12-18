// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currEnd = 0, farthest = 0;
        int ans = 0;
        for(int i=0;i<n-1;i++) {
            farthest = max(farthest, i+nums[i]);
            if(i==currEnd) {
                ans++;
                currEnd = farthest;
            }
        }
        return ans;
    }
};