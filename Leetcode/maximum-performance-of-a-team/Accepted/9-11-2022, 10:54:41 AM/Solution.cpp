// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++) {
            vec.push_back({-efficiency[i], -speed[i]});
        }
        sort(vec.begin(), vec.end());
        const long long mod = 1e9+7;
        long long ans = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++) {
            sum += (-vec[i].second);
            pq.push(-vec[i].second);
            
            if(pq.size()>k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, (sum*(-vec[i].first)));
        }
        return ans%mod;
    }
};