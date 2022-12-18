// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hash;
        hash[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(hash.find(sum-k)!=hash.end()) {
                ans += hash[sum-k];
            }
            hash[sum]++;
        }
        return ans;
    }
};