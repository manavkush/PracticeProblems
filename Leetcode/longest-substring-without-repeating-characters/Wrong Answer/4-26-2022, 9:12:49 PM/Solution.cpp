// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int prev = -1;
        unordered_map<char,int> hash; 
        int n = s.length();
        for(int i=0;i<n;i++) {
            hash[s[i]]++;
            if(hash.size()<i-prev) {
                hash.clear();
                hash[s[i]]++;
                prev = i-1;
            } else {
                ans = max(ans, (int)hash.size());
            }
        }
        return ans;
    }
};