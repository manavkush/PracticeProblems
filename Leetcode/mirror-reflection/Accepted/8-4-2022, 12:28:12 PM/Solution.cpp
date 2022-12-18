// https://leetcode.com/problems/mirror-reflection

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while((p&1)==0 and (q&1)==0) {
            p>>=1;
            q>>=1;
        }
        return 1 - p%2 + q%2;
    }
};