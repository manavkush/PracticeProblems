// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    long long rem = (long long)(target - nums[i])-(long long)nums[j] - (long long)nums[k];
                    auto pos = lower_bound(nums.begin()+k+1, nums.end(), rem);
                    
                    if(pos==nums.end() || nums[pos-nums.begin()]!=rem) {
                        continue;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[k] };
                        temp.push_back(nums[pos-nums.begin()]);
                        ans.push_back(temp);
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