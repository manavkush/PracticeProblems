// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
private:
    int partition(vector<int>&nums, int left, int right) {
        int l = left+1;
        int r = right;
        int pivot = nums[left];
        while(l<=r) {
            if(nums[l] < pivot and nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if(nums[l] >= pivot)
                l++;
            if(nums[r] <= pivot)
                r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1, kth;
        while(1) {
            int idx = partition(nums, left, right);
            if(idx == k-1) {
                kth = nums[idx];
                break;
            } 
            if(idx<k-1) {
                left = idx+1;
            }
            if(idx>k-1) {
                right = idx-1;
            }
        }
        return kth;
    }
};