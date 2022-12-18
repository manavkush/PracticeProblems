// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        int width = r-l;
        while(l<r) {
            ans = max(ans, width*min(height[r], height[l]));
            if( height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
            width--;
        }
        return ans;
    }
};