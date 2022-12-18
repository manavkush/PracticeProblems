// https://leetcode.com/problems/min-stack

class MinStack {
private:
        stack<long long> st;    // top
        long long min;
public:
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        long long value = val*1ll;
        if(st.empty()) {
            st.push(value);
            min = value;
            return;
        }
        if(value>=min) {
            st.push(value);
        } else {
            st.push(2*value*1ll - min);
            min = value;
        }
    }
    
    void pop() {
        if(st.top()<min) {
            min = 2*min - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<min) {
            return (min + st.top())/2;
        }
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */