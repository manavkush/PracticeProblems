// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while(l<=r) {
            if(a[l]<=a[r]) {
                if(a[l]>=left_max) {
                    left_max = a[l];
                } else {
                    ans += left_max - a[l];
                }
                l++;
            } else {
                if(a[r]>=right_max) {
                    right_max = a[r];
                } else {
                    ans += right_max - a[r];
                }
                r--;
            }
        }
        return ans;
    }
};