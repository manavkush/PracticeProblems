// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++) {
            int x=nums[i];
            
            if(hash.find(target-x)!=hash.end()) {
                ans.push_back(i);
                ans.push_back(hash[target-x]);
                return ans;
            }
            
            hash[x] = i;
        }
        return ans;
    }
};