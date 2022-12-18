// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        
        vector<int> freq(26,0);
        int ans = 1;
        int l = 0, r = 0;
        for(r=0;r<n;r++) {
            // int chr = ;
            freq[s[r]-'A']++;
            int idx = max_element(freq.begin(), freq.end()) - freq.begin();
            if(freq[idx]>=r-l+1-k) {
                ans = max(ans, r-l+1);
                continue;
            } 
            while(l<r) {
                freq[s[l]-'A']--;
                l++;
                int idx = max_element(freq.begin(), freq.end()) - freq.begin();
                if(freq[idx]>=r-l+1-k) {
                    ans = max(ans, r-l+1);
                    break;
                }
                
            }
        }
        return ans;
    }
};