// https://leetcode.com/problems/minimum-interval-to-include-each-query

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        vector<pair<int,int>> newqueries;
        for(int i=0;i<m;i++) {
            newqueries.push_back({queries[i], i});
        }
        sort(newqueries.begin(), newqueries.end());
        sort(intervals.begin(), intervals.end());
        
        vector<int> finalans(m);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        int j = 0;
        for(int i=0;i<m;i++) {
            int ans = -1;
            int quer = newqueries[i].first;
            
            for(;j<n;j++) {
                int st = intervals[j][0], ed = intervals[j][1];
                if(st>quer) {
                    break;
                } else {
                    pq.push({ed-st+1, st, ed});
                }
            }
            while(!pq.empty()) {
                auto top = pq.top();
                int st = top[1], ed = top[2], sz = top[0];
                if(ed < quer) 
                    pq.pop();
                else {
                    ans = sz;
                    break;
                }
            }
            finalans[newqueries[i].second] = ans;
        }
        
        return finalans;
    }
};