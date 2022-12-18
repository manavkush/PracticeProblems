// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        int i = 0;
        int final = 0;
        if(n==0)    return 1;
        while(n) {
            if(n&1) {
                ;
            } else {
                final += (1<<i);
            }
            n = n>>1;
            i++;
        }
        return final;
    }
};