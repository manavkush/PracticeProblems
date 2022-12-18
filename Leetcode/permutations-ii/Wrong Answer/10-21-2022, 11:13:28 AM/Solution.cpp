// https://leetcode.com/problems/permutations-ii

class Solution {
private:
    void util(vector<vector<int>> &result, vector<int> &curr, int idx) {
        int n = curr.size();
        if(idx==n) {
            result.push_back(curr);
            return;
        }
        util(result, curr, idx+1);
        for(int i=idx+1;i<n;i++) {
            if(curr[i]!=curr[idx]) {
                swap(curr[i], curr[idx]);
                util(result, curr, idx+1);
                swap(curr[i], curr[idx]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        util(result, nums, 0);
        return result;
    }
};