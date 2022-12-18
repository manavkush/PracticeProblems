// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        unordered_map<int,int> hash;
        
        for(int i=n-1;i>=0;i--) {
            hash[nums[i]]=-1;
            for(int j=i+1;j<n;j++) {
                if(nums[j]%nums[i]==0) {
                    if(dp[j]+1>dp[i]) {
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                    }
                }
            }
        }
        int pos = 0;
        for(int i=0;i<n;i++) {
            if(dp[i]>dp[pos]) {
                pos = i;
            }
        }
        vector<int> ans;
        do {
            ans.push_back(nums[pos]);
            pos = hash[pos];
        } while(pos!=-1);
        
        return ans;
    }
};