// https://leetcode.com/problems/make-array-strictly-increasing

class Solution {
private:
    const int INF = 1e5;
    
    int util(vector<vector<int>> &dp, vector<int> &arr1, vector<int>&newarr, int curr_idx, int prev_idx) {
        // cout<<curr_idx<<" "<<prev_idx<<endl;
        int n = arr1.size();
        int m = newarr.size();
        if(curr_idx>=n)
            return 0;
        int ans = INF;
        
        if(dp[curr_idx][prev_idx]!=-1)
            return dp[curr_idx][prev_idx];
        
        if(arr1[curr_idx]>newarr[prev_idx]) {
            ans = min(ans, util(dp, arr1, newarr, curr_idx+1, curr_idx+1));
        } 
        auto pos = upper_bound(newarr.begin()+n+1, newarr.end(), newarr[prev_idx]);
        if(pos!=newarr.end()) {
            int ret = 1+util(dp, arr1, newarr, curr_idx+1, pos-newarr.begin());
            ans = min(ans, ret);
        }
        // for(int j=n+1;j<m;j++) {
        //     if(newarr[j]>newarr[prev_idx]) {
        //         int ret = 1+util(dp, arr1, newarr, curr_idx+1, j);
        //         ans = min(ans, ret);
        //     }
        // }
        return dp[curr_idx][prev_idx] = ans;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        vector<int> newarr = {-1};
        sort(arr2.begin(), arr2.end());
        newarr.insert(newarr.end(), arr1.begin(), arr1.end());
        newarr.insert(newarr.end(), arr2.begin(), arr2.end());
        
        vector<vector<int>> dp( arr1.size()+1, vector<int> (newarr.size()+1, -1));
        
        int ans = util(dp, arr1, newarr, 0, 0);

        if(ans >= INF)
            return -1;
        return ans;
    }
};