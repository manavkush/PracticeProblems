// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int mod = 1000000;
        int target = 0, curr = 0, power = 1, n = haystack.size(), m = needle.size();
        for(int i=0;i<m;i++) {
            target = (target*26+(needle[i]-'a'))%mod;
            power = (power*26)%mod;
        }
        for(int i=0;i<n;i++) {
            curr = (curr*26+haystack[i]-'a')%mod;
            if(i<m-1) 
                continue;
            if(i>=m) {
                curr = (curr - (haystack[i-m]-'a')*power)%mod;
            }
            if(curr<0)
                curr += mod;
            if(curr == target) {
                if(haystack.substr(i-m+1, m)==needle) {
                    return i-m+1;
                }
            }
        }
        return -1;
    }
};