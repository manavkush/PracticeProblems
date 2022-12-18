// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        // vector<vector<int>> pref(n+1, vector<int>(26, 0));
        // for(int i=0;i<n;i++) {
        //     pref[i+1] = pref[i];
        //     pref[i+1][s[i]-'A']++;
        // }
        vector<int> freq(26,0);
        int ans = 1;
        int l = 0, r = 0;
        for(r=0;r<n;r++) {
            freq[s[r]-'A']++;
            int idx = max_element(freq.begin(), freq.end()) - freq.begin();
            if(freq[idx]>=r-l+1-k) {
                ans = max(ans, r-l+1);
                continue;
            } 
            while(l<r) {
                freq[s[l]-'A']--;
                int idx = max_element(freq.begin(), freq.end()) - freq.begin();
                if(freq[idx]>=r-l+1-k) {
                    ans = max(ans, r-l+1);
                    break;
                }
                l++;
            }
        }
        return ans;
    }
};