// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int,int> st;
        for(auto &x: people) {
            st[x]++;
        }
        int cnt = 0;
        while(!st.empty()) {
            auto high = (--st.end());
            (high->second)--;
            int left = (limit-high->first);
            
            if(high->second==0)
                st.erase(high);
            
            auto pos = st.upper_bound(left);
            if(pos!=st.begin()) {
                pos--;
                pos->second--;
                if(pos->second == 0)
                    st.erase(pos);
            }
            cnt++;
        }
        return cnt;
    }
};