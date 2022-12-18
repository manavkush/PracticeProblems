// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        // int i = 0;
        int ans = 0;
        int curr = 5;
        while(curr<=n) {
            ans += n/curr;
            curr *= 5;
        }
        return ans;;
    }
};