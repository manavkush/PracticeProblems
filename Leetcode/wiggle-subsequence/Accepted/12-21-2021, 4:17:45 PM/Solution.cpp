// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size();
        
        vector<int > pos(n, 1);
        vector<int > neg(n, 1);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(a[j]<a[i]) {
                    pos[i] = max(pos[i], neg[j]+1);
                } else if(a[j]>a[i]) {
                    neg[i] = max(neg[i], pos[j]+1);
                }
            }
        }
        return max(pos[n-1], neg[n-1]);
        
        
    }
};