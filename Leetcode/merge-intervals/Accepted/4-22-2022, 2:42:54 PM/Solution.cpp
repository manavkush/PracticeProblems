// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int l=-1,r=-1;
        for(auto &x: intervals) {
            int ll = x[0];
            int rr = x[1];
            if(ll>r) {
                if(l!=-1) {
                    vector<int> temp = {l, r};
                    ans.push_back(temp);
                }
                l = ll;
                r = rr;
            } else {
                r = max(rr, r);
            }
        }
        vector<int> temp = {l, r};
        ans.push_back(temp);
        return ans;
    }
};