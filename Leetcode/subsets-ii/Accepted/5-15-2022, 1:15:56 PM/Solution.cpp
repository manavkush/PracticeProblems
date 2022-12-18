// https://leetcode.com/problems/subsets-ii

class Solution {
private: 
    void util(vector<vector<int>>&ans, vector<int> &nums, vector<int> &arr, int idx) {
        // Pushing a valid subset
        ans.push_back(arr);
        // Making subset of size + 1
        for(int i=idx;i<nums.size();i++) {
            if((i!=idx) and (nums[i]==nums[i-1])) {
                continue;
            }
            arr.push_back(nums[i]);
            util(ans, nums, arr, i+1);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> arr;
        vector<vector<int>> ans;
        util(ans, nums, arr, 0);
        
        return ans;
        
    }
};