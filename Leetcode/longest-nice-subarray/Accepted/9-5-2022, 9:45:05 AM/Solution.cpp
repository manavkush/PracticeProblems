// https://leetcode.com/problems/longest-nice-subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> bits(32,0);
        int l=0, r=0, used=0;
        
        for(r=0;r<n;r++) {
            
            while(used & nums[r]) {
                used ^= nums[l++];
            }
            used ^= nums[r];
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};