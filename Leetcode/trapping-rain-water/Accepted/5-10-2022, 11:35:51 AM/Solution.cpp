// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> max_left(n), max_right(n);
        int high = 0;
        for(int i=0;i<n;i++) {
            high = max(high, height[i]);
            max_left[i] = high;
        }
        high = 0;
        for(int i=n-1;i>=0;i--) {
            high = max(high, height[i]);
            max_right[i] = high;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans+= min(max_right[i], max_left[i])-height[i];
        }
        return ans;
    }
};