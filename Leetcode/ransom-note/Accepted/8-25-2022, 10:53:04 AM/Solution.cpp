// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hash;
        for(auto &x: magazine) {
            hash[x]++;
        }
        for(auto &x: ransomNote) {
            hash[x]--;
            if(hash[x]<0)
                return false;
        }
        return true;
    }
};