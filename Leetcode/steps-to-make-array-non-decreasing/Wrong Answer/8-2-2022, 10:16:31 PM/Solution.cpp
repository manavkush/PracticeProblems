// https://leetcode.com/problems/steps-to-make-array-non-decreasing

class Solution {
public:
    int totalSteps(vector<int>& a) {
        vector<int> res;
        int n = a.size();
        int ans = 0;
        for(int i=1;i<n;i++) {
            if(a[i]>=a[i-1]) continue;
            int j = i;
            while(j<n and a[j]<a[i-1]) {
                j++;
            }
            ans = max(ans, j-i);
            i = j-1;
        }
        return ans;
    }
};