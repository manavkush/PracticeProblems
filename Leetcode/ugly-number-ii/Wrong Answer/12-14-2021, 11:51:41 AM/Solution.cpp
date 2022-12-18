// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> st1, st2;
        st1 = st2 = {1};
        while(st2.size() < n) {
            for(auto x: st1) {
                for(int i=1;i<15;i++) {
                    st2.insert(i*2);
                }
                for(int i=1;i<10;i++) {
                    st2.insert(i*3);
                }
                for(int i=1;i<=6;i++) {
                    st2.insert(i*5);
                }
            }
            st1 = st2;
        }
        return *(next(st1.begin(),n-1));
    }
};