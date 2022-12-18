// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto posL = lower_bound(nums.begin(), nums.end(), target);
        vector<int> ans;
        if(posL==nums.end() || (*posL != target)) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        auto posR = upper_bound(nums.begin(), nums.end(), target);
        posR--;
        ans.push_back(posL-nums.begin());
        ans.push_back(posR-nums.begin());
        return ans;
    }
};