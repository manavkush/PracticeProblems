// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        long long m = n;
        int i=0;
        if(m&(m-1)) {
            return false;
        } else {
            int cnt = 0;
            for(int i=0;i<31;i++) {
                if(m>>i & 1) {
                    return (!(i&1));
                }
            }
            return false;
        }
    }
};