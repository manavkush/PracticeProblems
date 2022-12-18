// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& A) {
      int n = A.size();
    vector<int> pos(n), neg(n);
    pos[0] = neg[0] = A[0];
    for(int i=1;i<n;i++) {
        if(A[i]==0) {
            pos[i] = 0;
            neg[i] = 0;
        } else if(A[i]<0) {
            if(A[i-1]==0) {
                pos[i] = 0;
                neg[i] = A[i];
            } else {
                pos[i] = neg[i-1]*A[i];
                neg[i] = min(pos[i-1]*A[i], A[i]);
            }
        } else {
            if(A[i-1]==0) {
                pos[i] = A[i];
                neg[i] = 0;
            } else {
                pos[i] = max(pos[i-1]*A[i], A[i]);
                neg[i] = neg[i-1]*A[i];
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        ans = max(ans, pos[i]);
    }
    return ans;
    }
};