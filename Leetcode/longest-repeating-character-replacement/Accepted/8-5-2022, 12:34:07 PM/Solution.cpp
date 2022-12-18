// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<vector<int>> pref(n+1, vector<int>(26, 0));
        for(int i=0;i<n;i++) {
            pref[i+1] = pref[i];
            pref[i+1][s[i]-'A']++;
            // sort(pref[i+1].begin(), pref[i+1].end());
        }
        int ans = 1;
        int l = 0, r = 0;
        for(l=0;l<=r;l++) {
            while(r<n) {
                vector<int> diff(26);
                for(int i=0;i<26;i++) {
                    diff[i] = pref[r+1][i]-pref[l][i];
                }
                int idx = max_element(diff.begin(), diff.end()) - diff.begin();
                if(diff[idx]>=r-l+1-k) {
                    ans = max(ans, r-l+1);
                    r++;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};