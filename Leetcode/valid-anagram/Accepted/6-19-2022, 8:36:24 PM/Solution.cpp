// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) 
            return false;
        unordered_map<char,int> hs;
        for(int i=0;i<s.length();i++) {
            hs[s[i]]++;
            hs[t[i]]--;
        }
        for(auto &x: hs) {
            if(x.second!=0)
                return false;
        }
        return true;
    }
};