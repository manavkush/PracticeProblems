// https://leetcode.com/problems/min-stack

class MinStack {
private:
        stack<long long> st;    // top
        int min;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            min = val;
            return;
        }
        if(val>=min) {
            st.push(val);
        } else {
            st.push(2*(long long)val-min);
            min = val;
        }
    }
    
    void pop() {
        if(st.top()<min) {
            min = 2*(long long)min-st.top();
            st.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<min) {
            return min;
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