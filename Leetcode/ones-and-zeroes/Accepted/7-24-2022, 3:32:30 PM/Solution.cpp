// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<int> ones(len), zeros(len);
        for(int i=0;i<len;i++) {
            int one = 0;
            for(int j=0;j<strs[i].length();j++) {
                one += (strs[i][j] - '0');
            }
            ones[i] = one;
            zeros[i] = strs[i].length() - one;
        }
        // for(int i=0;i<len;i++) {
        //     cout<<ones[i]<<" "<<zeros[i]<<endl;
        // }
        int dp[605][105][105]; // len, m, n
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<len;i++) {
            for(int j=0;j<=n;j++) { // ones
                for(int k=0;k<=m;k++) { // zeros
                    
                    dp[i+1][j][k] = dp[i][j][k];
                    
                    if(ones[i] <= j and zeros[i] <= k) {
                        dp[i+1][j][k] = max(dp[i+1][j][k], 1+dp[i][j-ones[i]][k-zeros[i]]);
                    }
                }
            }
        }
        return dp[len][n][m];
    }
};