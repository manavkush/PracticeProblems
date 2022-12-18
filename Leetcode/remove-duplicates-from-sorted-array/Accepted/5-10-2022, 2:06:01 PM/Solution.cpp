// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            nums[j] = nums[i];
            while(i<n and nums[i]==nums[j]) {
                i++;
            }
            i--;
            j++;
        }
        return j;
    }
};