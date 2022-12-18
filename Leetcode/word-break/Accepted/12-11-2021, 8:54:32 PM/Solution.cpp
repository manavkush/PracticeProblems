// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> hash;
        for(int i=0;i<wordDict.size();i++) {
            hash[wordDict[i]]++;
        }
        vector<int> indices;
        indices.push_back(0);
        
        for(int i=0;i<s.length();i++) {
            for(auto x: indices) {
                if(hash.find(s.substr(x, i-x+1)) != hash.end()) {
                    indices.push_back(i+1);
                    break;
                }
            }
        }
        if(indices.back()==s.length()) {
            return 1;
        } 
        return 0;
    }
};