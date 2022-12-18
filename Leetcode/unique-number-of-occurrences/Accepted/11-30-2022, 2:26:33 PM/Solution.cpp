// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> f, ff;
        for(auto &x: arr) {
            f[x]++;
        }
        for(auto &x: f) {
            ff[x.second]++;
        }
        for(auto &x: f) {
            if(ff[x.second]!=1)
                return false;
        }
        return true;
    }
};