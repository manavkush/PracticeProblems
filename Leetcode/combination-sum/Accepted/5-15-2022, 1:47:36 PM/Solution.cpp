// https://leetcode.com/problems/combination-sum

class Solution {
private: 
    void util(vector<vector<int>> &ans, int idx, vector<int> &candidates, vector<int> &curr, int target) {
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++) {
            if(candidates[i]<=target) {
                curr.push_back(candidates[i]);
                util(ans, i, candidates, curr, target-candidates[i]);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        util(ans, 0, candidates, curr, target);
        return ans;
    }
};