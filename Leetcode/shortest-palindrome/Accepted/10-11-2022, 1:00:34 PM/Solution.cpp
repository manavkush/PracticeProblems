// https://leetcode.com/problems/shortest-palindrome

class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        s2 = s + "*" + s2;
        int m = s2.length();
        int i=0, j=1;
        vector<int> lps(m);
        
        while(j<m) {
            if(s2[i]==s2[j]) {
                lps[j] = i+1;
                i++; j++;
            } else {
                if(i==0) {
                    j++;
                } else {
                    i = lps[i-1];
                }
            }
        }
        int len = lps.back();
        string left = s.substr(len);
        reverse(left.begin(), left.end());
        return left + s;
    }
};