// https://leetcode.com/problems/longest-nice-subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> bits(32,0);
        int l=0, r=0;
        
        for(;r<n;r++) {
            for(int j=0;j<31;j++) {
                if((nums[r]>>j) & 1)
                    bits[j]++;
            }
            while(l<r and (*max_element(bits.begin(), bits.end()) > 1)) {
                for(int j=0;j<31;j++) {
                    if((nums[l]>>j) & 1)
                        bits[j]--;
                }
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};