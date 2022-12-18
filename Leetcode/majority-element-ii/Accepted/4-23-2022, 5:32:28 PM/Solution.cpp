// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x=INT_MAX, y=INT_MAX, n = nums.size();
        int countx = 0, county=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==x) {
                countx++;
            } else if(nums[i]==y) {
                county++;
            } else if(x==INT_MAX) {
                x = nums[i];
                countx = 1;
            } else if(y==INT_MAX) {
                y = nums[i];
                county = 1;
            } else {
                countx--;
                county--;
                if(countx==0) {
                    x = INT_MAX;
                }
                if(county==0) {
                    y = INT_MAX;
                }
            }
        }
        vector<int> elements;
        if(x!=INT_MAX) {
            int cnt = 0;
            for(auto el: nums) {
                cnt += (x==el);
            }
            if(cnt>n/3)
                elements.push_back(x);            
        }
        if(y!=INT_MAX) {
            int cnt = 0;
            for(auto el: nums) {
                cnt += (y==el);
            }
            if(cnt>n/3)
                elements.push_back(y);
        }
        return elements;
    }
};