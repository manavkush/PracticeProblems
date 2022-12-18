// https://leetcode.com/problems/wildcard-matching

class Solution {
private:
    bool util(string &s, string &p, int i, int j) {
        int n = s.length();
        int m = p.length();
        
        if(i>=n and j>=m) {
            return true;
        } else if(i>=n || j>=m) {
            return false;
        }
        
        if(s[i]==p[j]) {
            return util(s,p, i+1, j+1);
        } else if(p[j]=='?') {
            return util(s, p, i+1, j+1);
        } else if(p[j]=='*') {
            return util(s, p, i, j+1) || util(s, p, i+1,j);
        } else {
            return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        if(s.length()==0 && p.length()==0)
            return true;
        if(s.length()==0 || p.length()==0)
            return false;
        return util(s, p, 0, 0);
    }
};