// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        // int dp[n+1];
        vector<int> ans;
        // memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<n;i++) {
            auto low = lower_bound(ans.begin(), ans.end(), a[i]);
            if(low==ans.end()) {
                ans.push_back(a[i]);
            } else {
                ans[low-ans.begin()] = a[i];
            }
            // dp[i] = 1;
            // for(int j=0;j<i;j++) {
            //     if(a[i]>a[j]) {
            //         dp[i] = max(dp[j]+1, dp[i]);
            //     }
            // }
        }
        return ans.size();
        
        
    }
};