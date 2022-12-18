// https://leetcode.com/problems/count-integers-in-intervals

class CountIntervals {
private:
    map<int,int> mp;
    int cnt=0;
public:
    CountIntervals() {
    }
    
    void add(int left, int right) {
        auto it = mp.upper_bound(left);
        if(it!=mp.begin() and prev(it)->second >= left) {
            it--;
        }
        for(; it!=mp.end() and it->first <= right; ) {
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= (it->second - it->first + 1);
            mp.erase(it++); // passed iterator to erase and incremented before executing erase
        }
        mp[left] = right;
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