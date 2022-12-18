// https://leetcode.com/problems/subsets-ii

class Solution {
private: 
    void util(map<vector<int>,int>&hash, vector<int> &nums, vector<int> &arr, int idx) {
        if(idx==nums.size()) {
            hash[arr]++;
        } else {
            arr.push_back(nums[idx]);
            util(hash, nums, arr, idx+1);
            arr.pop_back();
            util(hash, nums, arr, idx+1);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>, int> hash;
        sort(nums.begin(), nums.end());
        vector<int> arr;
        util(hash, nums, arr, 0);
        vector<vector<int>> ans;
        for(auto x: hash) {
            ans.push_back(x.first);
        }
        return ans;
        
    }
};