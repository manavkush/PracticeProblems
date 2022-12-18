// https://leetcode.com/problems/permutations

class Solution {
private: 
    void util(vector<int>& nums, vector<vector<int>> &ans, int idx) {
        if(idx==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++) {
            swap(nums[idx], nums[i]);
            util(nums, ans, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        util(nums, ans, 0);
        return ans;
    }
};