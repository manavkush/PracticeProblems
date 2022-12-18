// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        priority_queue<pair<int,int>> pq;
        vector<pair<double,int>> ratios;
        
        for(int i=0;i<n;i++) {
            ratios.push_back({wage[i]*1.0/quality[i], i});
        }
        sort(ratios.begin(), ratios.end());
        // sorted based on ratio ( cost: quality);
        
        int totalquality = 0;
        for(int i=0;i<k;i++) {
            int idx = ratios[i].second;
            pq.push({quality[idx], idx});
            totalquality += quality[idx];
        }
        double ans = (totalquality*ratios[k-1].first);
        // cout<<ans<<" ";
        for(int i=k;i<n;i++) {
            auto top = pq.top(); pq.pop();
            totalquality-=quality[top.second];
            
            int newidx = ratios[i].second;
            pq.push({quality[newidx], newidx});
            totalquality+=quality[newidx];
            
            double curr = ratios[i].first*totalquality;
            ans = min(ans, curr);
            // cout<<ans<<" ";
        }
        return ans;
    }
};