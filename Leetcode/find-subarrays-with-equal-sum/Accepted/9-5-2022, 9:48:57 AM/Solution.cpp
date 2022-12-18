// https://leetcode.com/problems/find-subarrays-with-equal-sum

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hash;
        for(int i=0;i<n-1;i++) {
            int sum = nums[i]+nums[i+1];
            if(hash.find(sum)==hash.end()) {
                hash[sum]++;
            } else {
                return true;
            }
        }
        
        return false;
    }
};