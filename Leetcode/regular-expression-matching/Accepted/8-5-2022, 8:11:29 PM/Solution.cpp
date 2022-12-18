// https://leetcode.com/problems/regular-expression-matching

class Solution {
private:
    int util(vector<vector<int>> &dp, string &s, string &p, int i, int j) {
        int n = s.length(), m = p.length();
        
        // BASE CASES
        if(j<0)
            return i<0;
        if(dp[i+1][j+1]!=-1)
            return dp[i+1][j+1];
        if(i<0) {
            if(p[j]=='*') {
                return dp[i+1][j+1] = util(dp,s, p, i, j-2);
            }
            return dp[i+1][j+1] = 0;
        }
        
        // MAIN
        if(dp[i+1][j+1]!=-1)
            return dp[i+1][j+1];
        int ans = 0;
        if(s[i]==p[j]) {
            ans |= util(dp,s, p, i-1, j-1);
        } else if(p[j]=='.') {
            ans |= util(dp,s, p, i-1, j-1);
        } else if(p[j]=='*') {
            if(p[j-1]=='.'|| p[j-1]=='*'|| s[i]==p[j-1]) {
                // Case1: *-> 0
                // Case2: *-> 1
                // Case3: *-> further
                ans |= util(dp,s,p,i,j-2) | util(dp,s, p, i-1, j-2) | util(dp,s, p, i-1, j);
                
            } else {
                ans |= util(dp,s, p, i, j-2);
            }
        } 
        return dp[i+1][j+1] = ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1, -1));
        return util(dp,s, p, s.length()-1, p.length()-1);
    }
};