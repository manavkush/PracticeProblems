// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if(n==0 || m==0)    return max(n,m);
        vector<vector<int>> dp(n+1, vector<int> (m+1, 1000));
        dp[0][0] = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(word1[i]==word2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = min({dp[i][j+1], dp[i][j], dp[i+1][j]})+1;
                }
            }
        }
        return dp[n][m];
    }
};