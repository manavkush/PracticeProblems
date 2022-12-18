// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m, 0);
        int i = 1, len = 0;
        while(i<n) {
            if(needle[i]==needle[len]) {
                lps[i] = len+1;
                len++;
                i++;
            } else {
                if(len==0) {
                    i++;
                } else {
                    len = lps[len-1];
                }
            }
        }
        
        int j;
        i = j = 0;
        
        while(j<n) {
            if(needle[i]==haystack[j]) {
                i++; j++;
                
                if(i==m)
                    return j-m;
            } else {
                if(i==0) {
                    j++;
                } else {
                    i = lps[i-1];
                }
            }
        }
        return -1;
        
    }
};