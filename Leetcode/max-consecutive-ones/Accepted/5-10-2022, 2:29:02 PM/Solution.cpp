// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int ans = 0;
        while(i<n) {
            int cnt = 0;
            while(i<n and nums[i]==1) {
                cnt++;
                i++;
            }
            ans = max(ans, cnt);
            while(i<n and nums[i]==0) {
                i++;
            }
        }
        return ans;
    }
};