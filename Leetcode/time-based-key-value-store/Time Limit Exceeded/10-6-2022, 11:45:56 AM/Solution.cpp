// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
private:
    map<string, map<int,string>> hash;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        map<int,string> hashed = hash[key];
        auto pos = hashed.upper_bound(timestamp);
        
        if(pos == hashed.begin()) {
            return "";
        }
        return (prev(pos)->second);
    }
};