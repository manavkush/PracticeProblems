// https://leetcode.com/problems/house-robber-ii

class Solution {
private:
    int util(int ii, int ff, vector<int> &nums) {
        int a = 0, b = 0, res = 0;
        
        for(int i=ii;i<ff;i++) {
            res = max(b+nums[i], a);
            b = a;
            a = res;
        }
        return res;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        return max(util(0, n-1, nums), util(1, n, nums));
    }
};