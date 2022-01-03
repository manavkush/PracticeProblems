class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int> hash;
        for(auto x: wordDict) {
            hash[x]++;
        }
        int n = s.length();
        vector<bool> dp(n+1, 0);
        dp[0] = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if(dp[j]==1 and hash.find(s.substr(j, i-j+1))!=hash.end()) {
                    dp[i+1] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};