// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
private:
    int partition(vector<int>&nums, int l, int r) {
        int el = nums[l], i = l+1, f = r;
        while(i<=f) {
            if(nums[i]<el and nums[f]>el) {
                swap(nums[i], nums[f]);
                i++;f--;
            }
            while(i<=f and nums[i]>=el) {
                i++;
            }
            while(i<=f and nums[f]<=el) {
                f--;
            }
        }
        swap(nums[l], nums[f]);
        return f;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        while(1) {
            int idx = partition(nums, l, r);
            if(idx==k-1) {
                return nums[idx];
            } 
            if(idx<k-1) {
                l = idx+1;
            } 
            if(idx>k-1) {
                r = idx-1;
            }
        }
        return 0;
    }
};