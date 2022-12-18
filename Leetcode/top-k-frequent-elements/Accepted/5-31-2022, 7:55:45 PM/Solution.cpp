// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int n = nums.size();
        for(auto &x: nums) {
            freq[x]++;
        }
        for(auto &x: freq) {
            pq.push({x.second, x.first});
            if(pq.size()>k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};