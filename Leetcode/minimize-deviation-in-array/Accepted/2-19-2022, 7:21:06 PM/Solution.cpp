// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            while(nums[i]&1) {
                nums[i] <<= 1;
            }
            st.insert(nums[i]);
        }
        int ans = -(*st.begin() - *(st.rbegin()));
        while((*st.rbegin())%2==0) {
            st.insert((*st.rbegin())/2);
            st.erase(--st.end());
            ans = min(ans, (*st.rbegin() - (*st.begin())));
        }
        return ans;
    }
};