// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int inc = 0, dec = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='I')
                inc++;
            else dec++;
        }
        dec = inc+dec;
        inc = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='I') {
                ans.push_back(inc++);
            } else {
                ans.push_back(dec--);
            }
        }
        if(s.back()=='I') {
            ans.push_back(inc);
        } else {
            ans.push_back(dec);
        }
        return ans;
    }
};