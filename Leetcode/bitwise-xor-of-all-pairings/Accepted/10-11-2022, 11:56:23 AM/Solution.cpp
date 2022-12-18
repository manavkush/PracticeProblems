// https://leetcode.com/problems/bitwise-xor-of-all-pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0;
        int xor2 = 0;
        for(int i=0;i<nums1.size();i++) {
            xor1 ^= nums1[i];
        }
        for(int i=0;i<nums2.size();i++) {
            xor2 ^= nums2[i];
        }
        int ans = 0;
        if(nums2.size() & 1) {
            ans ^= xor1;
        }
        if(nums1.size() & 1) {
            ans ^= xor2;
        }
        
        return ans;
    }
};