// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        vector<int> inc(n+1,0);
        vector<int> dec(n+1,0);
        int ans = 0;
        for(int i=n-2;i>=0;i--) {
           if(a[i]>a[i+1])  {
               dec[i] = dec[i+1]+1;
           }
        }
        for(int i=1;i<n;i++) {
            if(a[i]>a[i-1]) {
                inc[i] = inc[i-1]+1;
            }
            if(inc[i] and dec[i])
            ans = max(ans, inc[i]+dec[i]+1);
        }
        if(ans<3) return 0;
        return ans;
    }
};