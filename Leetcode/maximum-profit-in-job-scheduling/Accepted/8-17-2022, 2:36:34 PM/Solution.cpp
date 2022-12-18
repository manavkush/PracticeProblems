// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> vec;
        int n = startTime.size();
        for(int i=0;i<n;i++) {
            vec.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(vec.begin(), vec.end());
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--) {
            int start = vec[i].first.first;
            int end = vec[i].first.second;
            int profit = vec[i].second;
            
            int not_taken = dp[i+1];
            int next = lower_bound(vec.begin(), vec.end(), make_pair(make_pair(end, INT_MIN), INT_MIN))-vec.begin();
            int taken = profit+dp[next];
            dp[i] = max(taken, not_taken);
        }
        return dp[0];
    }
};