// https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto &x: nums) {
            if(!(x&1))
            sum += x;
        }
        vector<int> ans;
        for(auto &x: queries) {
            int val = x[0], idx = x[1];
            if(val&1) {
                if(nums[idx]&1) {
                    sum += (nums[idx]+val);
                } else {
                    sum -= (nums[idx]);
                }
            } else {
                if(nums[idx]&1) {
                    ;
                } else {
                    sum += val;
                }
            }
            
            nums[idx] += val;
            ans.push_back(sum);
        }
        return ans;
    }
};