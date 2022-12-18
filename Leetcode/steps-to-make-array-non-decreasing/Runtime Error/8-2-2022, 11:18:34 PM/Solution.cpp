// https://leetcode.com/problems/steps-to-make-array-non-decreasing

class Solution {
public:
    int totalSteps(vector<int>& a) {
        vector<int> res;
        int n = a.size();
        int ans = 0;
        vector<int> vec;
        for(int i=1;i<n;i++) {
            if(a[i]<a[i-1]) {
                vec.push_back(i-1);
            }
        }
        int cnt = 0;
        int sz = vec.size();
        vector<int> dp(sz);
        for(int i=sz-1;i>=0;i--) {
            if(i == sz-1) {
                int len = 0;
                for(int j=vec[i]+1; j<n and a[j]<a[i];j++) {
                    len++;
                }
                dp[i] = len;
            } else {
                int len = 0;
                for(int j=vec[i]+1; j<n and a[j]<a[i];j++) {
                    len++;
                    if(j==vec[i+1]) {
                        len += dp[i+1];
                        break;
                    }
                }
                dp[i] = len;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};