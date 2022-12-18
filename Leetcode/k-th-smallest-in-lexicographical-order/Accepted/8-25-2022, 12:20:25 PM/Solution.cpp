// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order

class Solution {
private:
    int getgap(long x, long y, int n) {
        int gap = 0;
        while(x<=n) {
            if(y<=n) {
                gap += (y-x);
            } else {
                gap += (n+1-x);
            }
            x*=10;
            y*=10;
        }
        return gap;
    }
public:
    int findKthNumber(int n, int k) {
        k--;
        long curr = 1;
        while(k>0) {
            int gap = getgap(curr, curr+1, n);
            if(gap <= k) {
                k -= gap;
                curr = curr+1;
            } else {
                k--;
                curr = curr*10;
            }
        }
        return curr;
    }
};