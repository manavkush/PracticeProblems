// https://leetcode.com/problems/permutations

class Solution {
private: 
    void util(vector<int>& nums, vector<vector<int>> &ans, vector<int> &taken, vector<int> &perm, int idx) {
        if(idx==nums.size()) {
            ans.push_back(perm);
            return;
        }
        for(int i=0;i<taken.size();i++) {
            if(!taken[i]) {
                taken[i] = 1;
                perm.push_back(nums[i]);
                util(nums, ans, taken, perm, idx+1);
                perm.pop_back();
                taken[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> taken(n,0);
        vector<int> perm;
        util(nums, ans, taken, perm, 0);
        return ans;
    }
};