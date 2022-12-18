// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int diff = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='(' || s[i]=='*')
                diff++;
            else diff--;
            
            if(diff<0)
                return false;
        }
        diff = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]==')' || s[i]=='*') {
                diff++;
            } else {
                diff--;
            }
            if(diff<0)
                return false;
        }
        
        return true;
    }
};