// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        priority_queue<int> pq(nums.begin(), nums.begin()+k);
        vector<int> ans = {pq.top()};
        for(int i=0;i<nums.size();i++) {
            hash[nums[i]]++;
            pq.push(nums[i]);
            if(i<k) continue;
            hash[nums[i-k]]--;
            while(!pq.empty() and hash[pq.top()]==0) {
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};