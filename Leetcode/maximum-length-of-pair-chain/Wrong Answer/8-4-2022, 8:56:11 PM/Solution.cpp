// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>> vec;
        int n = pairs.size();
        for(int i=0;i<n;i++) {
            vec.push_back({pairs[i][0], pairs[i][1]});
        }
        vector<int> dp(n+1, 1);
        sort(vec.begin(), vec.end());
        
        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                if(vec[i].second<vec[j].first) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp[0];
    }
};