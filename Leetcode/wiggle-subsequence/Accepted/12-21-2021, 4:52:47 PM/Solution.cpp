// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size();
        
        int up = 1, down = 1;
        
        for(int i=1;i<n;i++) {
            if(a[i]>a[i-1]) {
                up = down +1;
            } else if(a[i]<a[i-1]) {
                down = up +1;
            }
        }
        return max(up, down);
        
        
    }
};