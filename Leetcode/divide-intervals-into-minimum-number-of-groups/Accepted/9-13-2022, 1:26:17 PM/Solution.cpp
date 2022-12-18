// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups

class Solution {
private:
    // bool static comp(vector<int> &a, vector<int> &b) {
    //     if(a[1]!=b[1]) {
    //         return a[1]<b[1];
    //     } else {
    //         return a[0]<b[0];
    //     }
    // }
public:
    int minGroups(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        int curr = 0;
        vector<int> pos(1e6+2);
        for(auto &x: intervals) {
            pos[x[0]]++;
            pos[x[1]+1]--;
        }
        for(int i=1;i<=1e6;i++) {
            pos[i] += pos[i-1];
        }
        for(int i=1;i<=1e6;i++) {
            ans = max(ans, pos[i]);
        }
        return ans;
    }
};