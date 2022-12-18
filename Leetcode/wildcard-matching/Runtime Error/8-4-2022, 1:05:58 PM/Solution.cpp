// https://leetcode.com/problems/wildcard-matching

class Solution {
private:
    
    bool util(vector<vector<int>> &dp, string &s, string &p, int i, int j) {
        int n = s.length();
        int m = p.length();
        
        if(j>=m) {
            return (i>=n);
        }
        if(i>=n and p[j]!='*') {
            return false;
        }
        
        bool ans = false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(p[j]=='*') {
            ans |= util(dp,s, p, i, j+1) || util(dp,s, p, i+1, j+1) || util(dp,s, p, i+1,j);
        } else if(s[i]==p[j]) {
            ans |= util(dp,s,p, i+1, j+1);
        } else if(p[j]=='?') {
            ans |= util(dp,s, p, i+1, j+1);
        }  else {
            ans = false;
        }
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        // if(s.length()==0 && p.length()==0)
        //     return true;
        // if(s.length()==0 || p.length()==0)
        //     return false;
        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1, -1));
        return util(dp,s, p, 0, 0);
    }
};