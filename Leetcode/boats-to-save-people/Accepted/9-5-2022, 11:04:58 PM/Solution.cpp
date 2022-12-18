// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> st;
        for(auto &x: people) {
            st.insert(x);
        }
        int cnt = 0;
        while(!st.empty()) {
            auto top = *(--st.end());
            st.erase(--st.end());
            int left = (limit-top);
            auto pos = st.upper_bound(left);
            if(pos!=st.begin()) {
                pos--;
                st.erase(pos);
            }
            cnt++;
        }
        return cnt;
    }
};