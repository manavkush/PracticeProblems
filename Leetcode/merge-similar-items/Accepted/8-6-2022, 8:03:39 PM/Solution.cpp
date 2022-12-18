// https://leetcode.com/problems/merge-similar-items

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> hash;
        for(auto &x: items1) {
            hash[x[0]]+=x[1];
        }
        for(auto &x: items2) {
            hash[x[0]]+=x[1];
        }
        vector<vector<int>> ans;
        for(auto &x: hash) {
            ans.push_back({x.first, x.second});
        }
        return ans;
    }
};