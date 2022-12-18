// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int prev = bottom;
        int ans = 0;
        for(int i=0;i<special.size();i++) {
            ans = max(ans,special[i]-prev);
            
            prev = special[i]+1;
        }
        ans = max(ans, top-special.back());
        return ans;
    }
};