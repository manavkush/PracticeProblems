// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1, INT_MIN);
        vector<int> suff(n+1, INT_MIN);
        int result = INT_MIN;
        int sum = 0;
        int curr = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];  // Storing prefix
            pref[i+1] = max(pref[i], sum);
            
            curr += nums[i];
            if(curr>result) {
                result = curr;
            }
            if(curr<0) curr = 0;
        }
        sum = 0;
        for(int i=nums.size()-1;i>=0;i--) {
            sum +=  nums[i];
            suff[i] = max(suff[i+1], sum);
        }
        for(int i=0;i<n;i++) {
            result = max(result, pref[i]+suff[i]);
        }
        return result;
        
        
    }
};