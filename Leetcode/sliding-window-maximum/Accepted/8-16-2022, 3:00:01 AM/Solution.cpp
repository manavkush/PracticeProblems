// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int,int>> st;
        for(int i=0;i<k;i++) {
            st.insert({nums[i], i});
        }
        vector<int> ans = {prev(st.end())->first};
        for(int i=k;i<n;i++) {
            st.insert({nums[i], i});
            st.erase({nums[i-k], i-k});
            ans.push_back(prev(st.end())->first);
        }
        return ans;
    }
};