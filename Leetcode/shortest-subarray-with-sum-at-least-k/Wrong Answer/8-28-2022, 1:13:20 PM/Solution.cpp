// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> pref(n+1, 0);
        for(int i=0;i<n;i++) {
            pref[i+1] = pref[i] + (long long)nums[i];
        }
        
        long long ans = 1e10;
        deque<int> q;
        
        for(int i=0;i<=n;i++) {
            while(!q.empty() and pref[q.back()] >= pref[i])
                q.pop_back();
            
            while(!q.empty() and pref[q.front()]<= pref[i]-k) {
                ans = min(ans, pref[i]-pref[q.front()]);
                q.pop_front();
            }
            q.push_back(i);
        }
        return ans == 1e10 ? -1 : ans;
    }
};