// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pos = 1;
        int neg = 1;
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                pos = 0;
                neg = 0;
            } else if(nums[i] > 0) {
                
                pos = max(nums[i], pos*nums[i]);
                neg = min(nums[i], neg*nums[i]);
            } else {
                int old_pos = pos;
                pos = max(nums[i], neg*nums[i]);
                neg = min(nums[i], old_pos*nums[i]);
            }
            ans = max(ans, pos);
            // cout<<ans<<" "<<pos<<" "<<neg<<endl;
        }
        
        return ans;
    }
};