// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> hash;
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > st;
        for(int i=0;i<=n-k;i++) {
            st.push({nums[i], i});
        }
        vector<int> ans;
        int l = 0;
        for(int i=1;i<k;i++) {
            while(st.top().second<l) {
                st.pop();
            }
            ans.push_back(st.top().first);
            l = st.top().second+1;
            st.pop();
            st.push({nums[n-k+i], n-k+i});
        }
        while(st.top().second < l) {
            st.pop();
        }
        ans.push_back(st.top().first);
        
        return ans;
    }
};