// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
private:
    int util(map<pair<int,int>,int> &dp, vector<int> &nums, vector<int> &multipliers, int i, int f) {
        int n = nums.size();
        int m = multipliers.size();
        
        int used = i+(n-1-f);
        if(used >= multipliers.size())
            return 0;
        
        if(dp.find({i, f})!=dp.end()) 
            return dp[{i,f}];
        
        int ans1 = multipliers[used]*nums[i] + util(dp, nums, multipliers, i+1, f);
        int ans2 = multipliers[used]*nums[f] + util(dp, nums, multipliers, i, f-1);
        
        return dp[{i,f}] = max(ans1, ans2);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        map<pair<int,int>,int> dp;
        
        return util(dp, nums, multipliers, 0, nums.size()-1);
    }
};