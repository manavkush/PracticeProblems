// https://leetcode.com/problems/super-egg-drop

class Solution {
private:
    int util(vector<vector<int>> &dp,int n, int k) {
        if(n==0 || n==1) return n;
        if(k==1) return n;
        if(dp[n][k]!=-1) return dp[n][k];
        
        int ans = 1e7;
        
        int l = 1;
        int r = n;
        
        while(l<=r) {
            int mid = (l+r)/2;
            int broken = util(dp, mid-1, k-1);
            int not_broken = util(dp, n-mid, k);
            
            int high = max(broken, not_broken)+1;
            
            if(broken < not_broken) {
                l = mid+1;
            } else {
                r = mid-1;
            }
            
            ans = min(ans, high);
        }
        // for(int i=1;i<=n;i++) {
        //     ans = min(ans, max(util(dp,i-1, k-1), util(dp,n-i, k)) + 1);
        // }
        return dp[n][k] = ans;
    }
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return util(dp,n, k);
    }
};