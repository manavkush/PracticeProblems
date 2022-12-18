// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m, 0);
        int len = 0, i=1;
        while(i<m) {
            if(needle[i]==needle[len]) {
                len++;
                lps[i]=len;
                i++;
            } else {
                if(len)
                    len = lps[len-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        // for(auto &x: lps) {
        //     cout<<x<<" ";
        // }
        int j=0;
        int count = 0;
        i=0;
        while(i<n) {
            // cout<<i<<" "<<j<<endl;
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