// https://leetcode.com/problems/regular-expression-matching

class Solution {
private:
    bool util(string &s, string &p, int i, int j) {
        int n = s.length(), m = p.length();
        
        // BASE CASES
        if(i<0 && j<0) 
            return 1;
        else if(i<0 || j<0)
            return 0;
        
        // MAIN
        
        if(s[i]==p[j]) {
            return util(s, p, i-1, j-1);
        } else if(p[j]=='.') {
            return util(s, p, i-1, j-1);
        } else if(p[j]=='*') {
            if(p[j-1]=='.'|| p[j-1]=='*'|| s[i]==p[j-1]) {
                // Case1: *-> 0
                // Case2: *-> 1
                // Case3: *-> further
                return util(s,p,i,j-2) | util(s, p, i-1, j-2) | util(s, p, i-1, j);
                
            } else {
                return util(s, p, i, j-2);
            }
        } 
        return 0;
    }
public:
    bool isMatch(string s, string p) {
        return util(s, p, s.length()-1, p.length()-1);
    }
};