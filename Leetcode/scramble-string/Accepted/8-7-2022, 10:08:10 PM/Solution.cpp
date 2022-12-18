// https://leetcode.com/problems/scramble-string

class Solution {
private:
    int util(string &s1, string &s2, int x1, int x2, int y1, int y2, int dp[30][30][30][30]) {
        int n = x2-x1+1;
        if(x1==x2) {    // when length == 1
            if(s1[x1]==s2[y1]) {
                return 1;
            } else {
                return 0;
            }
        }
        if(dp[x1][x2][y1][y2]!=-1) 
            return dp[x1][x2][y1][y2];
        int ans = 0;
        for(int len=1;len<n;len++) {
            int a11 = util(s1, s2, x1, x1+len-1, y1, y1+len-1, dp);
            int a12 = util(s1, s2, x1+len, x2, y1+len, y2, dp);
            
            int a21 = util(s1, s2, x1, x1+len-1, y2-len+1, y2, dp);
            int a22 = util(s1, s2, x1+len, x2, y1, y2-len, dp);
            
            ans |= (a11&&a12) | (a21&&a22);
        }
        return dp[x1][x2][y1][y2] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int dp[30][30][30][30];
        memset(dp, -1, sizeof(dp));
        return util(s1, s2, 0, n-1, 0, n-1, dp);
    }
};