// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
private:
    bool util(vector<int> &nums, vector<int> &vec, int idx) {
        if(idx==nums.size())
            return true;
        int sz = vec.size();
        int max_el = *max_element(vec.begin(), vec.end());
        if(max_el < nums[idx])
            return false;
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
        
        if(tot%k != 0) return false;
        vector<int> vec(k, tot/k);
        sort(nums.begin(), nums.end(), greater<int> ());
        return util(nums, vec, 0);
    }
};