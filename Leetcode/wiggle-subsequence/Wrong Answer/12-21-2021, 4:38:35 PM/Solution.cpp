// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size();
        
        vector<int > pos(n, 1);
        vector<int > neg(n, 1);
        
        for(int i=1;i<n;i++) {
            if(a[i]>a[i-1]) {
                pos[i] = neg[i-1] + 1;
                neg[i] = neg[i-1];
            } else if(a[i]<a[i-1]) {
                neg[i] = pos[i-1] + 1;
                pos[i] = pos[i-1];
            }
        }
        return max(pos[n-1], neg[n-1]);
        
        
    }
};