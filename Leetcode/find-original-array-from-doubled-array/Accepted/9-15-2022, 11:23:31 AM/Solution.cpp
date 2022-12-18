// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> hash;
        for(auto &x: changed) {
            hash[x]++;
        }
        sort(changed.begin(), changed.end());
        vector<int> ans;
        for(auto &x: changed) {
            if(hash.find(x)==hash.end())
                continue;
            
            if(hash.find(2*x)==hash.end()) {
                return vector<int> ();
            } else {
                ans.push_back(x);
                hash[2*x]--;
                if(hash[2*x]==0)
                    hash.erase(2*x);
                hash[x]--;
                if(hash[x]==0)
                    hash.erase(x);
            }
        }
        if(hash.empty()) {
            return ans;
        } 
        return vector<int>();
    }
};