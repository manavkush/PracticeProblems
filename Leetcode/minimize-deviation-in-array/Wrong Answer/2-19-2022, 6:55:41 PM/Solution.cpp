// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            while(!(nums[i]&1)) {
                nums[i] >>= 1;
            }
            st.insert(nums[i]);
        }
        int ans = INT_MAX;
        int beg,end;
        beg = (*st.begin());
        end = (*prev(st.end()));
        int curr = end - beg;
        while(curr<ans) {
            ans = curr;
            st.insert(2*beg);
            st.erase(beg);
            beg = *st.begin();
            end = *(--st.end());
            curr = end-beg;
        }
        return ans;
    }
};