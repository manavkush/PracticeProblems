// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=-1;
        int countx = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==x) {
                countx++;
            } else if(countx==0) {
                x = nums[i];
                countx++;
            } else {
                countx--;
            }
        }
        return x;
    }
};