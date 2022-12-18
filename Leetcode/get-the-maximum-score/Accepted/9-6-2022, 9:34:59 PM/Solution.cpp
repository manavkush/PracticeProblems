// https://leetcode.com/problems/get-the-maximum-score

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        long long mod = 1e9+7;
        
        int i=0, j=0;
        long sum1=0, sum2=0;
        while(i<n && j<m) {
            if(nums1[i] > nums2[j]) {
                sum2 += nums2[j++];
            } else if(nums1[i] < nums2[j]) {
                sum1+=nums1[i++];
            } else {
                sum1 = sum2 = max(sum1, sum2) + nums1[i];
                i++, j++;
            }
        }
        while(i<n) {
            sum1+=nums1[i++];
        }
        while(j<m) {
            sum2+=nums2[j++];
        }
        return max(sum1, sum2)%mod;
    }
};