// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> next_great(n, -1);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() and temperatures[st.top()]<temperatures[i]) {
                next_great[st.top()] = i;       
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++) {
            if(next_great[i]==-1) {
                next_great[i] = 0;
            } else {
                next_great[i] = next_great[i]-i;
            }
        }
        return next_great;
        
    }
};