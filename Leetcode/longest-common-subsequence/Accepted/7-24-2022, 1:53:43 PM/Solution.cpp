// https://leetcode.com/problems/longest-common-subsequence

class Solution {
private:
    int util(vector<vector<int>> &dp, string &s1, string &s2, int i, int j) {
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i]==s2[j]) {
            dp[i][j] = 1+util(dp, s1, s2, i-1, j-1);
        } else {
            dp[i][j] = max(util(dp, s1, s2, i-1, j), util(dp, s1, s2, i, j-1));
        }
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        // vector<vector<int>> dp(1001, vector<int> (1001, 0));
        
        vector<int> curr(1001), prev(1001);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(text1[i]==text2[j])
                    curr[j+1] = 1+prev[j];
                else {
                    curr[j+1] = max(prev[j+1], curr[j]);
                }
            }
            prev = curr;
        }
        return curr[m];
    }
};