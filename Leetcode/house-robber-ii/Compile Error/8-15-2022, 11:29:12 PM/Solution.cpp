// https://leetcode.com/problems/house-robber-ii

class Solution {
private:
    int util(vector<int> &nums, int i, int f) {
        int prev = 0, prevprev = 0;
        for(int idx=i;idx<=f;idx++) {
            int curr = max(prev, prevprev+nums[idx]);
            prevprev = prev;
            prev = curr;
        }
        return max(prev, prevprev);        
    }
public:
    int rob(vector<int>& nums) {
        if(n==1)
            return nums[0];
        int n = nums.size();
        return max(util(nums, 0, n-2),util(nums, 1, n-1));
    }
};