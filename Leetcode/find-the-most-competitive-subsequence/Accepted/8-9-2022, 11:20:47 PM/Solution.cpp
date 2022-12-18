// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> next_small(n+1);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() and nums[i] < nums[st.top()]) {
                next_small[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            next_small[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        int idx = 0;
        for(int i=k;i>0;i--) {
            while(next_small[idx]!=-1 and next_small[idx]<=n-i) {
                idx = next_small[idx];
            }
            ans.push_back(nums[idx]);
            idx++;
        }
        
        return ans;
    }
};