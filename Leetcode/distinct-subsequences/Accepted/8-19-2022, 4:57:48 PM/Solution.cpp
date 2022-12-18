// https://leetcode.com/problems/distinct-subsequences

class Solution {
private:
    int util(vector<vector<int>> &dp, string &s, string &t, int i, int j) {
        int n = s.length(), m = t.length();
        if(i==n)
            return j==m;
        if(j==m) {
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans1 = util(dp,s, t, i+1, j);
        int ans2 = 0;
        if(s[i]==t[j]) {
            ans2 = util(dp,s, t, i+1, j+1);
        }
        return dp[i][j] = ans1+ans2;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        return util(dp,s, t, 0, 0);
    }
};