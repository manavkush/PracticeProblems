// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference

class Solution {
private:
    int total;
    int ans;
    void util(vector<int> &nums, int idx, int n, int curr) {
        int m = nums.size();
        if(n==0) {
            ans = min(ans, abs(total-2*curr));
            return;
        } else if(idx==m) {
            return;
        }
        // taken 
        util(nums, idx+1, n-1, curr+nums[idx]);
        // not taken
        util(nums, idx+1, n, curr);
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        ans = INT_MAX;
        total = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0;
        util(nums, 0, n, curr);
        
        return ans;
    }
};