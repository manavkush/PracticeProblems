// https://leetcode.com/problems/min-stack

class MinStack {
private:
        unordered_map<int,int> hash;
        stack<int> st;
        priority_queue<int,vector<int>, greater<int>> pq;
public:
    MinStack() {

    }
    
    void push(int val) {
        hash[val]++;
        st.push(val);
        pq.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        hash[val]--;
        while((!pq.empty()) and (hash[pq.top()]==0))
            pq.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return pq.top();
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