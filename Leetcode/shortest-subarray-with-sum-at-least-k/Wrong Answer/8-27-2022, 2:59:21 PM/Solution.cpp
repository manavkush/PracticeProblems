// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
private:
    bool check(vector<int> &nums,vector<long long> &pref, int len, int k) {
        // cout<<"* "<<len<<" "<<k<<endl;
        long long sum = pref[len];
        if(sum>=k)
            return true;
        int n = nums.size();
        for(int i=len+1;i<=n;i++) {
            sum = ((long long)pref[i]-(long long)pref[i-len]);
            if(sum>=k)
                return true;
        }
        return false;
    }
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);
        for(int i=0;i<n;i++) {
            pref[i+1] = (long long)pref[i] + (long long)nums[i];
        }
        int l = 0, r = n+1;
        while(l+1<r) {
            // cout<<l<<" "<<r<<endl;
            int mid = (l+r)/2;
            if(check(nums, pref, mid, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if(r==n+1)
            return -1;
        return r;
    }
};