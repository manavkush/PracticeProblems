// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double div = log10(n)/log10(3);
        if(div - (int)div == 0) {
            return true;
        }
        return false;
    }
};