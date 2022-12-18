// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1e9+7;
        int n = arr.size();
        vector<int> pref(n+1, 0);
        vector<int> suff(n+1, 0);
        
        for(int i=0;i<n;i++) {
            int ford_idx = i+1;
            int back_idx = n-1-i;
            
            pref[ford_idx] = pref[i] + arr[i];
            suff[back_idx] = pref[back_idx+1] + arr[i];
        }
        
        int fin_l, fin_r, l, r;
        fin_l = fin_r = -1;
        l = r = 0;
        int curr = 0;
        int sum = 0;
        
        for(int i=0;i<n;i++) {
            curr+=arr[i];
            if(curr<0)  {
                curr = 0;
                l = r = i+1;
            } else {
                if(curr>sum) {
                    sum = curr;
                    fin_l = l; fin_r = r;
                }
                r++;
            }
        }
        if(fin_l == -1) return 0;
        
        if(pref[n]>0) {
            return ((n*pref[n])%mod + sum);
        } else {
            return sum;
        }
        
    }
};