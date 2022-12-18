// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curr = strs[0];
        for(int i=1;i<strs.size();i++) {
            int j = 0;
            for(j=0;j<min(curr.length(), strs[i].length()); j++) {
                if(curr[j]!=strs[i][j]) {
                    break;
                }
            }
            curr = curr.substr(0, j);
        }
        return curr;
    }
};