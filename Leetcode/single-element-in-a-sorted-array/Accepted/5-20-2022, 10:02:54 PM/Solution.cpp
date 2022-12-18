// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while(l+1<r) {
            int i = (l+r)/2;
            if(i&1) {
                if(nums[i]==nums[i-1]) {
                    l = i+1;
                } else {
                    r = i;
                }
            } else {
                if(nums[i]!=nums[i-1]) {
                    l=i;
                } else {
                    r = i;
                }
            }
            // cout<<l<<" "<<r<<endl;
        }
        return nums[l];
    }
};