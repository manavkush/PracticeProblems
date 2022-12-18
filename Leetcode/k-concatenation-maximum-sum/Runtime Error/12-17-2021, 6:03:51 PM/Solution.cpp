// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1e9+7;
        int n = arr.size();
        int first = 0, curr = 0, ans = 0;
        
        
        for(int i=0;i<min(2, k);i++) {
            first = curr;
            for(int j=0;j<n;j++) {
                curr+=arr[j];
                if(curr<arr[j]) {
                    curr = arr[j];
                }
                ans = max(curr, ans)%mod;
                curr %= mod;
            }
        }
        
        if(curr - first > 0 and k>1) {
            ans = (ans + ((k-2)*(curr - first))%mod)%mod;
        }
        return ans;
        
    }
};