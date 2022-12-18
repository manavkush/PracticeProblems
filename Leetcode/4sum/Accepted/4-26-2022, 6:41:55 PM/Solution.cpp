// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int l = j+1;
                int r = n-1;
                long long rem = (long)target - (long)nums[i] - (long)nums[j];
                while(l<r) {
                    long curr = nums[l]+nums[r];
                    if(curr == rem) {
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(temp);
                        l++, r--;
                    } else if(curr<rem) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        vector<vector<int>> fin;
        for(int i=0;i<ans.size();i++) {
            if(i==0) {
                fin.push_back(ans[0]);
            } else {
                if(ans[i]!=ans[i-1]) {
                    fin.push_back(ans[i]);
                }
            }
        }
        return fin;
    }
};