// https://leetcode.com/problems/online-stock-span

class StockSpanner {
private:
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        st.push({-1, INT_MAX});
    }
    
    int next(int price) {
        int day = st.top().first+1;
        while(st.top().second <= price) {
            st.pop();
        }
        int last = st.top().first;
        st.push({day, price});
        return day-last;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */