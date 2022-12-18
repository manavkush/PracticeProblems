// https://leetcode.com/problems/combination-sum

class Solution {
private: 
    void util(vector<vector<int>> &ans, int idx, vector<int> &candidates, vector<int> &curr, int target) {
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        if(candidates[idx]<=target) {
            curr.push_back(candidates[idx]);
            util(ans, idx, candidates, curr, target-candidates[idx]);
            curr.pop_back();
        }
        if(idx<candidates.size()-1)
        util(ans, idx+1, candidates, curr, target);
        // for(int i=idx;i<candidates.size();i++) {
        //     if(candidates[i]<=target) {
        //         curr.push_back(candidates[i]);
        //         util(ans, i, candidates, curr, target-candidates[i]);
        //         curr.pop_back();
        //     }
        // }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        util(ans, 0, candidates, curr, target);
        return ans;
    }
};