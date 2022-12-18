// https://leetcode.com/problems/wildcard-matching

class Solution {
private:
    
    bool util(vector<vector<int>> &dp, string &s, string &p, int i, int j) {
        int n = s.length();
        int m = p.length();
        
        if(j>=m) {  // when pattern ended
            return (i>=n);
        }
        if(i>=n and p[j]!='*') {    // when string ended and pattern's last is not *
            return false;
        }
        
        bool ans = false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(p[j]=='*') {
            ans |= util(dp,s, p, i, j+1);   // when no character
            for(int ii=i;ii<n and s[i]==s[ii];ii++) {
                ans |= util(dp, s, p, ii+1, j+1);
            }
        } else if(s[i]==p[j] || p[j]=='?') {
            ans |= util(dp,s,p, i+1, j+1);
        } else {
            ans = false;
        }
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+2, vector<int> (p.length()+2, -1));
        return util(dp,s, p, 0, 0);
    }
};