// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factorlow;
        vector<int> factorshigh;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<=sqrt(n);i++) {
            if(n%i==0) {
                pq.push(i);
                if(i*i!=n) {
                    pq.push(n/i);
                }
            }
        }
        if(pq.size()<k) {
            return -1;
        }
        for(int i=0;i<k-1;i++) {
            pq.pop();
        }
        return pq.top();
    }
};