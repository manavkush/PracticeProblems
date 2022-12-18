// https://leetcode.com/problems/remove-boxes

class Solution {
private:
    int util(vector<vector<vector<int>>> &dp, vector<int> &boxes, int k, int i, int j) {
        if(i>j)
            return 0;
        if(i==j)
            return (k+1)*(k+1);
        if(dp[k][i][j]!=-1)
            return dp[k][i][j];
        int ans = (k+1)*(k+1) + util(dp, boxes, 0, i+1, j);     // removed the k+1 elements from start including the ith
        for(int m=i+1;m<=j;m++) {
            if(boxes[m]==boxes[i]) {
                ans = max(ans, util(dp, boxes, 0, i+1, m-1)+util(dp, boxes, k+1, m, j));
            }
        }
        return dp[k][i][j] = ans;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (n+1, 0)));
        /* 
            states-> [i][j][k] where i,j are end indices of any segment and k is the number of contiguous
                     elements equal to k before i
        */
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                dp[k][i][i] = (k+1)*(k+1);
            }
        }
        for(int k=n-1;k>=0;k--) {
            for(int i=n-1;i>=0;i--) {
                for(int j=i+1;j<n;j++) {
                    
                    dp[k][i][j] = max(dp[k][i][j], (k+1)*(k+1) + dp[0][i+1][j]);
                    for(int m=i+1;m<=j;m++) {
                        if(boxes[i]==boxes[m]) {
                            dp[k][i][j] = max(dp[k][i][j], dp[0][i+1][m-1]+dp[k+1][m][j]);
                        }
                    }
                }
            }    
        }
        return dp[0][0][n-1];
        // return util(dp, boxes, 0, 0, n-1);
    }
};