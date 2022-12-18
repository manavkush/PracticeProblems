// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int xr = nums[0];
        for(int i=1;i<nums.size();i++) {
            xr ^= (nums[i]^i);
        }
        return xr;
    }
};