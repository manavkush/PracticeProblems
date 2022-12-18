// https://leetcode.com/problems/permutations-ii

class Solution {
private:
    void util(vector<int> &nums, int idx, vector<int>&curr, unordered_map<int,int> &hash, vector<vector<int>> &ans) {
        int n = nums.size();
        if(idx==n) {
            ans.push_back(curr);
            return;
        }
        for(auto &x: hash) {
            if(x.second) {
                x.second--;
                curr.push_back(x.first);
                util(nums, idx+1, curr, hash, ans);
                curr.pop_back();
                x.second++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++) {
            hash[nums[i]]++;
        }
        // vector<int> taken(n);
        vector<vector<int>> ans;
        vector<int> curr;
        util(nums, 0, curr, hash, ans);
        return ans;
    }
};