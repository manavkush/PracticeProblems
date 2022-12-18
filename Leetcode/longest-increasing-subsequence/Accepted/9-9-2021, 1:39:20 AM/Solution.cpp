// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<n;i++) {
            dp[i] = 1;
            for(int j=0;j<i;j++) {
                if(a[i]>a[j]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
        
        int maxel = INT_MIN;
        for(int i=0;i<n;i++) {
            maxel = max(dp[i], maxel);
        }
        return maxel;
        
    }
};