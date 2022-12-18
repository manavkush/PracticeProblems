// https://leetcode.com/problems/steps-to-make-array-non-decreasing

class Solution {
public:
    int totalSteps(vector<int>& a) {
        vector<int> res;
        int n = a.size();
        int ans = 0;
        // vector<int> dp(n, 0);
        // stack<int> st;
        // for(int i=n-1;i>=0;i--) {
        //     while(!st.empty() and a[i]>a[st.top()]) {
        //         dp[i]++;
        //         dp[i] = max(dp[i], dp[st.top()]);
        //         st.pop();
        //     }
        //     ans = max(ans, dp[i]);
        //     st.push(i);
        // }
        // return ans;
        vector<int> vec;    // stores index of elements with next smaller
        for(int i=1;i<n;i++) {
            if(a[i]<a[i-1]) {
                vec.push_back(i-1);
            }
        }
        int cnt = 0;
        int sz = vec.size();
        vector<int> dp(sz);
        for(int i=sz-1;i>=0;i--) {
            int idx = vec[i];
            if(i == sz-1) {
                int len = 0;
                for(int j=idx+1; j<n and a[j]<a[idx];j++) {
                    len++;
                }
                dp[i] = len;
            } else {
                int len = 0;
                for(int j=idx+1; j<n and a[j]<a[idx];j++) {
                    len++;
                    if(j==vec[i+1]) {
                        len = max(len, dp[i+1]);
                        j+=dp[i+1];
                    }
                }
                dp[i] = len;
            }
        }
        for(auto x: vec) {
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x: dp) {
            cout<<x<<" ";
        }
        if(dp.empty()) return 0;
        return *max_element(dp.begin(), dp.end());
    }
};