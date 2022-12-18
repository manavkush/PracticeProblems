// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        priority_queue<int> pq;
        for(int i=0;i<k;i++) {
            pq.push(nums[i]);
            hash[nums[i]]++;
        }
        vector<int> ans;
        ans.push_back(pq.top());
        
        for(int i=k;i<nums.size();i++) {
            hash[nums[i]]++;
            pq.push(nums[i]);
            hash[nums[i-k]]--;            
            
            while(hash[pq.top()]==0) {
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};