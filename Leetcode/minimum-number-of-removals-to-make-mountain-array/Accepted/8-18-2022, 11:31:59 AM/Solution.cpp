// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> inc_front(n, 1);
        vector<int> inc_back(n, 1);
        
        for(int i=1;i<n-1;i++) {
            for(int j=0;j<i;j++) {
                if(a[i]>a[j]) {
                    inc_front[i] = max(inc_front[i], inc_front[j]+1);
                }
            }
        }
        for(int i=n-2;i>0;i--) {
            for(int j=n-1;j>i;j--) {
                if(a[i]>a[j])
                    inc_back[i] = max(inc_back[i], inc_back[j]+1);
            }
        }
        int ans = 0;
        for(int i=1;i<n-1;i++) {
            if(inc_front[i]!=1 and inc_back[i]!=1)
            ans = max(ans, inc_front[i]+inc_back[i]-1);
        }
        return n-ans;
    }
};