// https://leetcode.com/problems/super-egg-drop

// class Solution {
// public:
//     int superEggDrop(int k, int n) {
        
//     }
// };
class Solution {
public:
    int dp[1001] = {0};
    int util(int n, int k) {
        if(k>1) {
            if(dp[n]==0) {
                for(int i=1;i<=n;i++) {
                        dp[n] = min(dp[n]==0 ? n : dp[n], 1 + max(util(i-1, k-1), util(n-i, k)));
                }
            }
            return dp[n];
        } else {
            return n;
        }
        
    }
    int superEggDrop(int k, int n) {
        //  if(dp[n]==0) {
        //     for(int i=1;i<=n;i++) {
        //             dp[n] = min(dp[n]==0 ? n : dp[n], 1 + max(twoEggDrop(i-1), twoEggDrop(n-i)));
        //     }
        //  }
        // return dp[n];
        return util(n, k);
        
    }
};