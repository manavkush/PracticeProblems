// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
private:
    double util(vector<int> &nums1, vector<int> &nums2, int n, int m) {
        if(n>m) {
            return util(nums2, nums1, m, n);
        }
        int l = 0;
        int r = n;
        int medianpos = (n+m+1)/2;
        while(l<=r) {
            int mid= (l+r)/2;
            int mid2 = (medianpos-mid);
            
            int l1 = (mid ? nums1[mid-1] : INT_MIN);
            int l2 = (mid2 ? nums2[mid2-1] : INT_MIN);
            int r1 = (mid==n ? INT_MAX : nums1[mid]);
            int r2 = (mid2==m ? INT_MAX : nums2[mid2]);
            
            if(l1 <= r2 and l2<=r1) {
                if((n+m)&1) {
                    return max(l1, l2);
                } else {
                    return (max(l1,l2) + min(r1, r2))/2.0;
                }
            } else if(l1>r2) {
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        return 0.0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return util(nums1, nums2, nums1.size(), nums2.size());
    }
};