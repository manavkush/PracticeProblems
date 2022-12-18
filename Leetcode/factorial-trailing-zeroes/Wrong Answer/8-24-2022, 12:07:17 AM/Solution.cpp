// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int i = 0;
        int ans = 0;
        int curr = 5;
        while(curr<=n) {
            if(i) {
                ans -= n/curr;
            } else {
                ans += n/curr;
            }
            i ^= 1;
            curr *= 5;
        }
        return ans;;
    }
};