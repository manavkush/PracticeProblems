// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l=0,r=0;
        unordered_map<char,int> hash; 
        int n = s.length();
        for(r=0;r<n;r++) {
            hash[s[r]]++;
            
            while((r-l+1)>hash.size()) {
                hash[s[l]]--;
                if(hash[s[l]]==0) {
                    hash.erase(s[l]);
                }
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};