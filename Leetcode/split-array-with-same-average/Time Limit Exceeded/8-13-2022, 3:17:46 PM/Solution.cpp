// https://leetcode.com/problems/split-array-with-same-average

class Solution {
private:
    int total;
    bool util(vector<vector<vector<int>>> &dp, vector<int> &nums, int idx, int sz, int reqsum) {
        if(sz==0)   // if we've taken the required no of elements
            return reqsum==0;
        
        if(idx==-1)
            return 0;
        if(dp[idx][sz][reqsum]!=-1)
            return dp[idx][sz][reqsum];
        if(util(dp, nums, idx-1, sz, reqsum))
            return 1;
        if(nums[idx]<=reqsum) {
            return util(dp, nums, idx-1, sz-1, reqsum-nums[idx]);
        }
        return dp[idx][sz][reqsum]=false;
    }
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n, vector<int>(total+1, -1)));
        
        for(int sz=1;sz<n-1;sz++) {
            if((total*sz)%n==0) {
                if(util(dp, nums, n-1, sz, (total*sz)/n))
                    return true;
            }
        }
        return false;
    }
    
};