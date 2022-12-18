// https://leetcode.com/problems/snapshot-array


class SnapshotArray {
private:
    vector<vector<pair<int,int>>> vec;
    int cnt = 0;
public:
    SnapshotArray(int length) {
        vec.assign(length, vector<pair<int,int>> (1, {-1, 0}));
    }
    
    void set(int index, int val) {
        vec[index].push_back({cnt, val});
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        // auto pairs = {snap_id , INT_MAX};
        auto idx = upper_bound(vec[index].begin(), vec[index].end(), make_pair(snap_id, INT_MAX)) - vec[index].begin();
        idx--;
        return vec[index][idx].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */