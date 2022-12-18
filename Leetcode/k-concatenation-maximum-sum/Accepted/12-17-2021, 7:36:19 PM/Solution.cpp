// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long mod = 1e9+7;
        int n = arr.size();
        long long first = 0, curr = 0, ans = 0, total = 0;
        
        total = accumulate(arr.begin(), arr.end(), 0)%mod;
        
        for(int i=0;i<min(2, k);i++) {
            for(int j=0;j<n;j++) {
                curr = max((long long)arr[j], curr+arr[j]);
                ans = max(ans, curr);
            }
        }
        return max({0ll, ans, ans + total * max(0, k-2)})%mod;      
        
    }
};