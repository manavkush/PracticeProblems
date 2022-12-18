// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();
        vector<int> lps(m);
        
        int i=0, j=1;
        
        // Making lps
        while(j<m) {
            if(needle[i]==needle[j]) {
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
        
        // KMP
        i = 0, j = 0;
        while(j<n and i<m) {
            if(needle[i]==haystack[j]) {
                i++;
                j++;
            } else {
                if(i==0) {
                    j++;
                } else {
                    i = lps[i-1];
                }
            }
        }
        if(i==m) {
            return j-m;
        }
        return -1;
    }
};