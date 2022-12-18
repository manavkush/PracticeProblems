// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
private:
    int util(vector<vector<int>> &dp, vector<vector<int>>&ispallind, string& A, int i, int f) {
        if(i>f) return 0;
        if(dp[i][f]!=INT_MAX) {
            return dp[i][f];
        }
        if(ispallind[i][f]==1)
            return 0;

        int curr = INT_MAX;
        for(int ii=i;ii<=f;ii++) {
            if(ispallind[i][ii]) {
                curr = min(curr, 1+util(dp, ispallind, A, ii+1, f));
            }
        }
        return dp[i][f] = curr;
    }
public:
    int minCut(string A) {
        int n = A.length();
        vector<vector<int>> ispallind(n+1, vector<int> (n+1, 0));
        ispallind[0][0] = 1;
        for(int i=1;i<n;i++){
            ispallind[i][i] = 1;
            ispallind[i-1][i] = (A[i]==A[i-1] ? 1 : 0);
        }

        for(int len = 3;len<=n;len++) {
            for(int i=n-len;i>=0;i--) {
                if((A[i]==A[i+len-1]) and ispallind[i+1][i+len-2]==1) {
                    ispallind[i][i+len-1] = 1;
                }
            }
        }

        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        return util(dp, ispallind, A, 0, n-1);
    }
};