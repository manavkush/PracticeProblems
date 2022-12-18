// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
private:    
    unordered_map<string, vector<pair<int,string>>> hash;
    
    inline static auto myComp = [](pair<int,string> e1, pair<int,string> e2) {
      // if(e1.first!=e2.first)
      //   return e1.first<e2.first;
      // else
        return e1.first<e2.first;
    };
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> hashed = hash[key];
        auto pos = upper_bound(hashed.begin(), hashed.end(), make_pair(timestamp, "1" ), myComp);
        if(pos == hashed.begin()) {
            return "";
        }
        return (prev(pos)->second);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */