// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
private:
    bool util(vector<int> &nums, vector<int> &vec, int idx) {
        int sz = vec.size();
        if(idx==sz)
            return true;
        for(int i=0;i<sz;i++) {
            if(vec[i] >= nums[idx]) {
                vec[i] -= nums[idx];
                if(util(nums, vec, idx+1)) 
                    return true;
                vec[i] += nums[idx];
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        
        if(tot%k!=0) return false;
        vector<int> vec(k, tot/k);
        return util(nums, vec, 0);
    }
};