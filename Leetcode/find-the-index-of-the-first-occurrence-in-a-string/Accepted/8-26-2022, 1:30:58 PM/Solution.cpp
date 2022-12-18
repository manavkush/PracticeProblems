// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    /*
        In the brute approach we started to match the whole for every starting index
        of the haystack string.
        
        To counter this, we try to skip the repeated comparisons by trying to not move 
        the haystack counter back. We only move the needle counter back.
        
        In this approach we make an array lps ( longest proper prefix that's also a suffix)
        This array helps us to solve the question.
        We make the lps on the needle string.
    */
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m, 0);
        
        // MAKING THE LPS ARRAY
        int i = 1, len = 0;
        while(i<m) {
            /*
                If the elements of the two pointers are equal, then 
                we can increment both the pointers
            */
            if(needle[i]==needle[len]) {
                lps[i] = len+1;
                len++;
                i++;
            } else {
                /*
                    idx     0 1 2 3 4 5 6 7 8
                    str     a b c a b c a b d
                    lps     0 0 0 1 2 3 4 5 .
                    
                    len = 5, i = 8
                    
                    Now the str[8](d) doesn't match with str[5](c),
                    And str{3-7} matches with str{0-4}
                    we now try to see what's the largest 'proper' prefix of str{0, 4} that can be matched
                    with the suffix of str{3-7}. 
                    But as we know that str{3-7} == str{0, 4}, this problem
                    translates to finding the lps of str[4];
                    
                    We used proper prefix as if not used it will find itself as prefix
                    as hence we would be repeatedly take {0-4} which we can't extend beyong 4.
                    Actually we try to find another sequence
                    which can continue the pattern matching
                    
                */
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