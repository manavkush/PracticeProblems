// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
private:
    bool util(vector<vector<int>> &dp, string &s, int idx, int curr) {
        int n = s.length();
        if(idx==n) {
            return curr==0;
        }
        if(curr<0)
            return false;
        if(dp[idx][curr]!=-1)
            return dp[idx][curr];
        int ans = 0;
            
            
        if(s[idx]=='(') {
            ans = util(dp, s, idx+1, curr+1);
        } else if(s[idx]==')') {
            ans = util(dp,s, idx+1, curr-1);
        } else {
            ans = util(dp,s, idx+1, curr) || util(dp,s, idx+1, curr-1) || util(dp,s, idx+1, curr+1);
        }
        return dp[idx][curr] = ans;
    }
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return util(dp,s, 0, 0);
    }
};