// https://leetcode.com/problems/binary-trees-with-factors

class Solution {
private:
    const int mod = 1e9+7;
    long long util(vector<long long> &dp, vector<int> &arr, int index) {
        if(dp[index]!=-1)
            dp[index];
        long long prev = arr[index];
        int n = arr.size();
        int l = 0, r = index;
        long long ans = 1;
        while(l<=r) {
            long long a = arr[l],b = arr[r];
            if(prev==a*b) {
                long long left = util(dp,arr, l);
                long long right;
                if(a==b) {
                    ans = (ans + left*left%mod)%mod;
                } else {
                    right = util(dp, arr, r);
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
        vector<long long> dp(n+1, -1);
        for(int i=0;i<n;i++) {
            ans = (ans+util(dp, arr, i))%mod;
        }
        return ans;
    }
};