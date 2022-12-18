// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        int inc = 0, dec = 0;
        int ans = 0;
        for(int i=1;i<n;i++) {
            if(a[i]==a[i-1] || (dec>0 and a[i]>a[i-1])) inc = dec = 0;
            if(a[i]>a[i-1]) inc++;
            if(a[i]<a[i-1]) dec++;
            if(inc and dec) {
                ans = max(ans, inc+dec+1);
            }
        }
        return ans;
    }
};