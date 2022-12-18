// https://leetcode.com/problems/combination-sum-ii

class Solution {
    void util(int idx, vector<vector<int>> &ans, vector<int> &candidates, vector<int> &curr, int target) {
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        for(int i = idx;i<candidates.size();i++) {
            if(i!=idx and candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            
            curr.push_back(candidates[i]);
            util(i+1, ans, candidates, curr, target-candidates[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        util(0, ans, candidates, curr, target);
        return ans;
    }
};