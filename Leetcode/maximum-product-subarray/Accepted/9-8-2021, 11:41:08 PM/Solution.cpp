// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n = A.size();
    long long res=INT_MIN;
    // vector<int> prod(n+1,1);
    vector<vector<long long>> ans(n);
    int itr = 0;
    // bool flag = 0;
    long long mul= 1;
    for(int i=0;i<n;i++) {
        mul*=A[i];
        if(A[i]==0) {
            itr++;
        } else {
            ans[itr].push_back(A[i]);
        }
    }
    
    res = max(res, mul);
    for(int i=0;i<n;i++) {
        for(int j=1;j<ans[i].size();j++) {
            ans[i][j]=ans[i][j-1]*ans[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        int sz = ans[i].size();
        if(sz>0) {
            if(ans[i][sz-1]>0) {
                res = max(res, ans[i][sz-1]);
            } else {
            // cout<<sz<<"* ";
                long long a1 = ans[i][0];
                long long a2 = ans[i][sz-1];

                for(int j=0;j<sz-1;j++) {
                    if(ans[i][j]<0) {
                        a1 = ans[i][sz-1]/ans[i][j];
                        break;
                    }
                }
                for(int j=sz-1;j>=0;j--) {
                    if(ans[i][j]>0) {
                        a2 = ans[i][j];
                        break;
                    }
                }
                res = max(res, max(a1, a2));
            }
        }
    }
    return res;
    }
};