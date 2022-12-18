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
        int dp[105][105]; // len, m, n
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<len;i++) {
            for(int j=n;j>=0;j--) { // ones
                for(int k=m;k>=0;k--) { // zeros
                    
                    dp[j][k] = dp[j][k];
                    
                    if(ones[i] <= j and zeros[i] <= k) {
                        dp[j][k] = max(dp[j][k], 1+dp[j-ones[i]][k-zeros[i]]);
                    }
                }
            }
        }
        return dp[n][m];
    }
};