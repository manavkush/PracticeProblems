// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> pos(n+1, 0), neg(n+1, 0);
        pos[0] = INT_MIN;
        neg[0] = INT_MIN;
        for(int i=0;i<n;i++) {
            pos[i+1] = max(pos[i], values[i]+i);
        }
        for(int i=n-1;i>=0;i--) {
            neg[i] = max(neg[i+1], values[i]-i);
        }
        int res = INT_MIN;
        for(int i=1;i<n;i++) {
            res = max(res, pos[i]+neg[i]);
        }
        return res;
    }
};