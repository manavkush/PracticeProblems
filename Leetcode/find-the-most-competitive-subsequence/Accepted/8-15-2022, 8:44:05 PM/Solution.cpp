// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> next_smaller(n);
        stack<int> st;
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push(i);
            } else {
                while(!st.empty() and (nums[st.top()]>nums[i])) {
                    next_smaller[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()) {
            next_smaller[st.top()] = -1;
            st.pop();
        }
        
        int lim = n-k;
        int start = 0;
        vector<int> ans;
        for(int i=0;i<k;i++) {
            // cout<<start<<" "<<lim<<endl;
            while(next_smaller[start]!=-1 and next_smaller[start]<=lim) {
                start = next_smaller[start];
            }
            ans.push_back(nums[start]);
            start++;
            lim++;
        }
        return ans;
    }
};