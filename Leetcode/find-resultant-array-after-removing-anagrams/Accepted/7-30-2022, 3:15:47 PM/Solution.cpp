// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> words2  = words;
        for(int i=0;i<words.size();i++) {
            sort(words[i].begin(), words[i].end());
        }
        vector<string> ans = {words2[0]};
        for(int i=1;i<words.size();i++) {
            if(words[i]==words[i-1]) {
                continue;
            } else {
                ans.push_back(words2[i]);
            }
        }
        return ans;
    }
};