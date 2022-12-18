// https://leetcode.com/problems/regular-expression-matching

class Solution {
private:
    bool util(string &s, string &p, int i, int j) {
        int n = s.length(), m = p.length();
        
        // BASE CASES
        if(j==m) {
            return i>=n;
        }
        if(i==n) {
            for(int l=j;l<m;l++) {
                if(p[l]!='*')
                    return 0;
            }
            return 1;
        }
        // Main Cases
        
        if(s[i]==p[j]) {
            return util(s, p, i+1, j+1);
        } else if(p[j]=='.') {
            return util(s, p, i+1, j+1);
        } else if(p[j]=='*') {
            if(p[j-1]=='.'|| p[j-1]=='*') {
                for(int l=j;l<m;l++) {
                    if(util(s, p, i+1, l))
                        return 1;
                }
            } else {
                if(s[i]==p[j-1]) {
                    return util(s,p,i+1,j) | util(s,p,i+1,j+1);
                } else {
                    return 0;
                }
            }
        } 
        return 0;
    }
public:
    bool isMatch(string s, string p) {
        return util(s, p, 0, 0);
    }
};