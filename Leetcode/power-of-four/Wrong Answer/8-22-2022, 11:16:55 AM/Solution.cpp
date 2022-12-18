// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        return (n==1 || (n&3)==0);
    }
};