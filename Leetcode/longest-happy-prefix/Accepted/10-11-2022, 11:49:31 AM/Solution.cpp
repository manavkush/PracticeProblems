// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n);
        
        int i=0, j = 1;
        
        while(j<n) {
            if(s[i]==s[j]) {
                lps[j] = i+1; 
                i++, j++;
            } else {
                if(i==0) {
                    j++;
                } else {
                    i = lps[i-1];
                }
            }
        }
        
        return s.substr(0, lps[n-1]);
        
    }
};