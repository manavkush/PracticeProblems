// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<vector<int>> hash(26);
        for(int i=0;i<n;i++) {
            hash[s[i]-'a'].push_back(i);
        }
        int curr = INT_MAX;
        for(int i=0;i<26;i++) {
            if(hash[i].size()==1) {
                curr = min(curr, hash[i][0]);
            }
        }
        return curr==INT_MAX?-1:curr;
    }
};