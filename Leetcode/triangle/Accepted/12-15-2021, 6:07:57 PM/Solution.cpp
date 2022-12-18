// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        vector<int> newdp(n);

        for(int i=1;i<n;i++) {
            
            newdp[0] = dp[0] + triangle[i][0];
            newdp[i] = dp[i-1] + triangle[i][i];
            for(int j=1;j<i;j++) {
                newdp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp = newdp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};