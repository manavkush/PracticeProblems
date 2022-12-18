// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hash;
        deque<int> q;
        // We'll maintain a monotonic queue
        // Q.front() will be the maximum element in the range
        // When we move to next index, we try to push it from the back
        // and also maintaining the sorted order
        for(int i=0;i<k;i++) {
            hash[nums[i]]++;
            while(!q.empty() and q.back()<=nums[i])
                q.pop_back();
            q.push_back(nums[i]);
        }
        vector<int> ans;
        ans.push_back(q.front());
        for(int i=k;i<n;i++) {
            hash[nums[i]]++;
            hash[nums[i-k]]--;
            
            while(!q.empty() and q.back()<=nums[i])
                q.pop_back();
            q.push_back(nums[i]);
            
            while(!q.empty() and hash[q.front()]==0) {
                q.pop_front();
            }
            ans.push_back(q.front());
        }
        return ans;
    }
};