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
        int low = 0;
        int high = nums.size();
        if(nums[low]==target) {
            return low;
        }
        while(low+1<high) {
            int mid = (low+high)/2;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if(nums[mid]==target) {
                return mid;
            }
            if(nums[low]<=nums[mid]) {
                // left to mid is increasing
                if(target<=nums[mid] and target>=nums[low]) {
                    high = mid;
                } else {
                    low = mid;
                }
            } else {
                if(target > nums[low] || target < nums[mid]) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
        }
        return -1;
    }
};