// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0) {
            nums1 = nums2;
            return;
        } else if(n==0) {
            return;
        }
        int ptr = n+m-1;
        int p1 = m-1;
        int p2 = n-1;
        while(p1>=0 and p2>=0) {
            if(nums1[p1]>nums2[p2]) {
                nums1[ptr--] = nums1[p1--];
            } else {
                nums1[ptr--] = nums2[p2--];
            }
        }
        while(p1>=0) {
            nums1[ptr--] = nums1[p1--]; 
        }
        while(p2>=0) {
            nums2[ptr--] = nums2[p2--];
        }
    }
};