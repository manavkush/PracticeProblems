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
        int last = INT_MIN;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(last==INT_MIN) {
                cnt++;
                last = intervals[i][1];
            }
            if(intervals[i][0]>=last) {
                cnt++;
                last = intervals[i][1];
            }
        }
        return n-cnt;
        
    }
    
};