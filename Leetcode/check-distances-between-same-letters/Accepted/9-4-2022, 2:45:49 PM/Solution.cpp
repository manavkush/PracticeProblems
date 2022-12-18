// https://leetcode.com/problems/check-distances-between-same-letters

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<int,int> hash;
        int n = s.length();
        for(int i=0;i<n;i++) {
            int letter = s[i]-'a';
            if(hash.find(letter)==hash.end()) {
                hash[letter] = i;
            } else {
                if(i-hash[letter]-1!=distance[letter])
                    return false;
            }
        }
        return true;
    }
};