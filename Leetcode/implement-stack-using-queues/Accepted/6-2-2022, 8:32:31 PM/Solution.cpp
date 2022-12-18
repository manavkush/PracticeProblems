// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
private:
    queue<int> st;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = st.size();
        st.push(x);
        for(int i=0;i<sz;i++) {
            int el = st.front();
            st.pop();
            st.push(el);
        }
    }
    
    int pop() {
        int el = st.front();
        st.pop();
        return el;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */