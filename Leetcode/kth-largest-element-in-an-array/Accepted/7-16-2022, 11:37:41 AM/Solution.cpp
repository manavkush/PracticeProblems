// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
private:
    int partition(vector<int>&nums, int l, int r) {
        int el = nums[l];
        int i = l+1, f = r;
        while(i<=f) {
            if(nums[i]<el and nums[f]>el) {
                swap(nums[i], nums[f]);
                i++;f--;
            }
            if(nums[i]>=el) {
                i++;
            }
            if(nums[f]<=el) {
                f--;
            }
        }
        swap(nums[l], nums[f]);
        return f;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size()-1;
        while(1) {
            int idx = partition(nums, l, r);
            if(idx==k-1) {
                return nums[idx];
            } 
            if(idx<k-1) {
                l = idx+1;
            } else {
                r = idx-1;
            }
        }
        return 0;
    }
};