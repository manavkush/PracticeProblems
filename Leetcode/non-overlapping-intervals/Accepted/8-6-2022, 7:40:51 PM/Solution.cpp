// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
private:
    bool static comp(vector<int> &a, vector<int> &b) {
        if(a[1]!=b[1]) {
            return a[1]<b[1];
        } else {
            return a[0]<b[0];
        }
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        vector<vector<int>> lis;
        for(int i=0;i<n;i++) {
            if(lis.empty()) {
                lis.push_back(intervals[i]);
                continue;
            }
            int last = lis.back()[1];
            if(intervals[i][0]>=last) {
                lis.push_back(intervals[i]);
            }
        }
        return n-lis.size();
        
    }
    
};