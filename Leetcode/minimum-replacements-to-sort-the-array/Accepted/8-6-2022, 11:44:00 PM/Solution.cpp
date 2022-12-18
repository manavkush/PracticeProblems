// https://leetcode.com/problems/minimum-replacements-to-sort-the-array

class Solution {
public:
    long long minimumReplacement(vector<int>& a) {
        int n = a.size();
        int low = a[n-1];
        long long ans = 0;
        for(int i=n-2;i>=0;i--) {
            // cout<<ans<<" "<<low<<endl;
            if(a[i]<=low)  {
                low = a[i];
                continue;
            } 
            
            if(a[i]%low==0) {
                ans += a[i]/low-1;
                continue;
            } else {
                int div = a[i]/low;
                int places = div+1;
                low = (a[i]/places);
                ans += div;
                // int seclast = (a[i]-low*(div-1))/2;
                // low = seclast;
            }
            
        }
        return ans;
    }
};