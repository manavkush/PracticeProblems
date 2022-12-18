// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0, res = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++) {
            res = max(b+nums[i], a );
            b = a;
            a = res;
        }
        return max(a,b);
    }
};