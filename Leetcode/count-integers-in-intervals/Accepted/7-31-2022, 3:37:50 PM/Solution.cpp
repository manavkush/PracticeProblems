// https://leetcode.com/problems/count-integers-in-intervals

class CountIntervals {
private:
    set<pair<int,int>> st;
    int cnt=0;
public:
    CountIntervals() {
    }
    
    void add(int left, int right) {
        auto it = st.upper_bound({left, INT_MIN});
        if(it!=st.begin() and prev(it)->second >= left) {
            it--;
        }
        for(; it!=st.end() and it->first <= right; ) {
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= (it->second - it->first + 1);
            st.erase(it++); // passed iterator to erase and incremented before executing erase
        }
        st.insert({left, right});
        cnt += (right-left+1);
        
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */