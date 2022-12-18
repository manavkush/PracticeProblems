// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {

public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pref(n+1, 0);
        for(int i=0;i<n;i++) {
            pref[i+1] = pref[i] + cardPoints[i];
        }
        int ans = 0;
        for(int i=0;i<=k;i++) {
            ans = max(ans, pref[i]+pref[n]-pref[n-k+i]);
        }
        return ans;
    }
};