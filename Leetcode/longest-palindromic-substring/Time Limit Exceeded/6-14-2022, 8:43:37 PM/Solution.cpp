// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
private:
    bool util(string &s, int i, int f, int &first, int &len) {
        if(i>=f) {
            return true;
        }
        if(s[i]==s[f]) {
            bool rec = util(s, i+1, f-1, first, len);
            if(rec and (f-i+1 > len)) {
                len = f-i+1;
                first = i;
            }
            if(rec) {
                return true;
            }
        }
        util(s, i+1, f, first, len);
        util(s, i, f-1, first, len);
        return false;
        
    }
public:
    string longestPalindrome(string s) {
        int len = 1;
        int first = 0;
        util(s, 0, s.length()-1, first,len);
        return s.substr(first, len);
    }
};