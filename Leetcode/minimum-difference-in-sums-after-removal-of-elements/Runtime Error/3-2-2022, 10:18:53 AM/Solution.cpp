// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        
        vector<int> dp(3*n+1, 0);
        vector<int> dp2(3*n+1, 0);
        
        multiset <int> pq;
        int sum = 0;
        for(int i=0;i<n;i++) {
            pq.insert(nums[i]);
            sum+=nums[i];
        }
        dp[n-1] = sum;
        for(int i=n;i<2*n;i++) {
            auto el = *(--pq.end());
            if(nums[i]<=el) {
                pq.erase(--pq.end());
                pq.insert(nums[i]);
                sum += (nums[i] - el);
            }
            dp[i] = sum;
        }
        
        pq.clear();
        sum = 0;
        for(int i=3*n-1;i>=2*n;i--) {
            pq.insert(nums[i]);
            sum+=nums[i];
        }
        dp2[2*n] = sum;
        for(int i=2*n-1;i>=n;i--) {
            auto el = *pq.begin();
            if(nums[i]>=el) {
                pq.insert(nums[i]);
                pq.erase(pq.begin());
                sum += (nums[i] - el);
            }
            dp2[i] = sum;
        }
        int ans = INT_MAX;
        for(int i=n-1;i<2*n;i++) {
            ans = min(ans, dp[i]-dp2[i+1]);
        }
        return ans;
    }
};