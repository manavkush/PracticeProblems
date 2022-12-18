// https://leetcode.com/problems/number-of-arithmetic-triplets

class Solution {
public:
    int arithmeticTriplets(vector<int>& a, int diff) {
        set<vector<int>> st;
        int n = a.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(a[j]-a[i]==diff and a[k]-a[j]==diff) {
                        st.insert({a[i], a[j], a[k]});
                    }
                }
            }
        }
        return st.size();
    }
};