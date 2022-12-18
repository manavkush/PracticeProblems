// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> hash;
        
        set<pair<int,int>> st;
        for(int i=0;i<=n-k;i++) {
            st.insert({nums[i], i});
        }
        vector<int> ans;
        int l = 0;
        for(int i=1;i<k;i++) {
            while(st.begin()->second<l) {
                st.erase(st.begin());
            }
            ans.push_back(st.begin()->first);
            l = st.begin()->second+1;
            st.erase(st.begin());
            st.insert({nums[n-k+i], n-k+i});
            // cout<<l<<" ";
        }
        while(st.begin()->second<l) {
            st.erase(st.begin());
        }
        ans.push_back(st.begin()->first);
        
        return ans;
    }
};