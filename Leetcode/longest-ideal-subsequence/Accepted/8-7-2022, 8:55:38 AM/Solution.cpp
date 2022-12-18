// https://leetcode.com/problems/longest-ideal-subsequence

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int n = s.length();
        for(int i=n-1;i>=0;i--) {
            int ch = s[i]-'a';
            int curr = 1;
            for(int j=max(0, ch-k);j<=min(25, ch+k);j++) {
                curr = max(curr, dp[j]+1);
            }
            // for(int j=0;j<k and (j+ch<26);j++) {
            //     curr = max(curr, 1+dp[j+ch]);
            // }
            // for(int j=1;j<k and (ch-j>=0);j--) {
            //     curr = max(curr, 1+dp[ch-j]);
            // }
            dp[ch] = curr;
        }
        return *max_element(dp.begin(), dp.end());
    }
};