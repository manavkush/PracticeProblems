// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
private:
    int search(vector<int> &nums, int i, int f, int target) {
        if(f==-1)
            return -1;
        if(nums[i]==target)
            return i;
        if(nums[f]==target)
            return f;
        
        int l = i;
        int r = f+1;
        while(l+1<r) {
            int mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            
            if(nums[mid]<target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int l = -1;
        int r = nums.size()-1;
        while(l+1<r) {
            int mid = (l+r)/2;
            if(nums[mid]>nums[0]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        int ans1 = search(nums, 0, r-1, target);
        if(ans1==-1) {
            ans1 = search(nums, r, nums.size()-1, target);
        }
        return ans1;
    }
};