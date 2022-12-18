// https://leetcode.com/problems/binary-trees-with-factors

class Solution {
private:
    const int mod = 1e9+7;
    long long util(int dp[], int n, vector<int> &arr, int index) {
        if(dp[index]!=-1)
            dp[index];
        long long prev = arr[index];
        
        int l = 0, r = index;
        long long ans = 1;
        
        while(l<=r) {
            long long a = arr[l],b = arr[r];
            if(prev==a*b) {
                long long left = util(dp,n,arr, l);
                long long right;
                if(a==b) {
                    ans = (ans + left*left%mod)%mod;
                } else {
                    right = util(dp,n, arr, r);
                    ans = (ans + 2*left*right%mod)%mod;
                }
                l++; r--;
            } else if(prev>a*b) {
                l++;
            } else {
                r--;
            }
        }
        return dp[index] = ans;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long ans = 0;
        int dp[n];
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++) {
            ans = (ans+util(dp,n, arr, i))%mod;
        }
        return ans;
    }
};