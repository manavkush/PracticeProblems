// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m, 0);
        int j=0;
        for(int i=1;i<m;i++) {
            if(needle[i]==needle[j]) {
                lps[i]=lps[i-1]+1;
            } else {
                j=0;
                if(needle[i]==needle[j]) {
                    lps[i] = 1;
                    j++;
                }
            }
        }
        j=0;
        int count = 0, i=0;
        while(i<n) {
            if(needle[j]==haystack[i]) {
                j++;
                i++;
            } 
            if(j==m) {
                return i-m;
                // count++;
                // j = lps[j-1];
            } else if(i<n and needle[j]!=haystack[i]) {
                if(j!=0)
                    j = lps[j-1];
                else 
                    i++;
            }
        }
        return -1;
    }
};