// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int inc=0, dec=0;
        int ans = 0;
        for(int i=1;i<n;i++) {
            if(arr[i]>arr[i-1]) {
                dec = 0;
                inc++;
            } else if(arr[i]<arr[i-1]) {
                while(i<n and arr[i]<arr[i-1]) {
                    dec++;
                    i++;
                }
                if(inc!=0 and dec!=0) {
                    ans = max(ans, inc+dec+1);
                }
                inc = 1;
                dec = 0;
                
            } else {
                inc = 0, dec = 0;
            }
        }
        if(inc!=0 and dec!=0) {
            ans = max(ans, inc+dec+1);
        }        
        return ans;
    }
};