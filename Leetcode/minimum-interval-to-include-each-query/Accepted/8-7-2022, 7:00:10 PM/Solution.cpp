// https://leetcode.com/problems/minimum-interval-to-include-each-query

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        /* 
            Instead of taking the smallest queries one by one, 
            we take the smallest intervals one by one, 
            for all the matched queries, it will be the smallest interval.
        */
        set<pair<int,int>> newqueries;
        for(int i=0;i<m;i++) {
            newqueries.insert({queries[i], i});
        }
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {  return a[1]-a[0] < b[1]-b[0];  });
        
        vector<int> finalans(m, -1);
        for(auto &it : intervals) {
            // now we make a query iterator
            auto quer_it = newqueries.lower_bound({it[0], 0});
            
            while(quer_it!=newqueries.end() and quer_it->first <= it[1]) {
                finalans[quer_it->second] = it[1]-it[0]+1;
                quer_it = newqueries.erase(quer_it);
            } 
        }
        
        return finalans;
    }
};