// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> st1, st2;
        st1 = st2 = {1};
        while(st2.size() < 30*n) {
            for(auto x: st1) {
                st2.insert(x*2);
                st2.insert(x*3);
                st2.insert(x*5);
            }
            st1 = st2;
        }
        return *(next(st1.begin(),n-1));
    }
};