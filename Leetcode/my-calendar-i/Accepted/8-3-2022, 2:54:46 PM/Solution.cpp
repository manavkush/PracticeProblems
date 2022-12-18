// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(st.empty()) {
            st.insert({start, end});
            return true;
        }
        auto pos = st.upper_bound({start, INT_MIN});
        if(pos!=st.begin() and prev(pos)->second>start) {
            return false;
        } else {
            if(pos==st.end()) {
                st.insert({start, end});
                return true;
            } else if(pos->first < end) {
                return false;
            } else {
                st.insert({start, end});
                return true;
            }
        }
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */