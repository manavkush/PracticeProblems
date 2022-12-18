// https://leetcode.com/problems/stock-price-fluctuation

class StockPrice {
    multiset<int> st;
    map<int,int> hash;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(hash.find(timestamp)==hash.end()) {
            hash[timestamp] = price;
            st.insert(price);
            return;
        } else {
            st.erase(st.find(hash[timestamp]));
            hash[timestamp]--;
            if(hash[timestamp]==0)
                hash.erase(timestamp);
            
            hash[timestamp] = price;
            st.insert(price);
        }
    }
    
    int current() {
        return hash.rbegin()->second;
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */