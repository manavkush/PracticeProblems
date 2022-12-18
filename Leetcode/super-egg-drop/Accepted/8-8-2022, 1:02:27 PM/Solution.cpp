// https://leetcode.com/problems/super-egg-drop

class Solution {
private:
//     int util(vector<vector<int>> &dp,int n, int k) {
//         if(n==0 || n==1) return n;
//         if(k==1) return n;
//         if(dp[n][k]!=-1) return dp[n][k];
        
//         int ans = 1e7;
        
//         int l = 1;
//         int r = n;
        
//         while(l<=r) {
//             int mid = (l+r)/2;
//             int broken = util(dp, mid-1, k-1);
//             int not_broken = util(dp, n-mid, k);
            
//             int high = max(broken, not_broken)+1;
            
//             if(broken < not_broken) {
//                 l = mid+1;
//             } else {
//                 r = mid-1;
//             }
            
//             ans = min(ans, high);
//         }
//         return dp[n][k] = ans;
//     }
public:
    int superEggDrop(int k, int n) {
        
        int dp[n+1][k+1];
        memset(dp, -1, sizeof(dp));
        // vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        for(int i=0;i<=n;i++) {
            dp[i][1] = i;
        }
        for(int i=1;i<=k;i++) {
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        for(int i=2;i<=n;i++) { // floor
            for(int j=2;j<=k;j++) { // eggs
                
                int ans = 1e7;
                int l = 1;
                int r = i;

                while(l<=r) {
                    int mid = (l+r)/2;
                    int broken = dp[mid-1][j-1];
                    int not_broken = dp[i-mid][j];

                    int high = max(broken, not_broken)+1;

                    if(broken < not_broken) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                    ans = min(ans, high);
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][k];
    }
};