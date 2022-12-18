// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int diff = right - left;
        int ans = 0;
        for(int i=0;i<31;i++) {
            if( (left&(1<<i)) and (right&(1<<i))) {
                if(diff <= (1<<i)/2) {
                    ans |= (1<<i);
                }
            }
        }
        return ans;
    }
};