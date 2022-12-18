// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> ans = {a[0]};
        for(int i=1;i<n;i++) {
            if(ans.back() < a[i]) {
                ans.push_back(a[i]);
            } else {
                int pos = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[pos] = a[i];
            }
        }
        return ans.size();
        
    }
};