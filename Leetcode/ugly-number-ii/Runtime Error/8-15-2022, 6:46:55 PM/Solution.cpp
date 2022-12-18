// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> pq;
        pq.insert(1);
        
        for(int i=0;i<n-1;i++) {
            int top = *pq.begin(); pq.erase(pq.begin());
            pq.insert(2*top);
            pq.insert(3*top);
            pq.insert(5*top);
        }
        return *pq.begin();
    }
};