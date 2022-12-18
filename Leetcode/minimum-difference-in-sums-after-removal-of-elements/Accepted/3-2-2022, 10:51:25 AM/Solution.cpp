// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        
        vector<long long> dp(3*n+1, 0);
        vector<long long> dp2(3*n+1, 0);
        
        priority_queue<int> pq;
        priority_queue <int, vector<int>, greater<int>> pq2;
        
        long long sum = 0;
        for(int i=0;i<n;i++) {
            pq.push(nums[i]);
            sum+=nums[i];
        }
        dp[n-1] = sum;
        for(int i=n;i<2*n;i++) {
            auto el = pq.top();
            if(nums[i]<=el) {
                pq.pop();
                pq.push(nums[i]);
                sum += (nums[i] - el);
            }
            dp[i] = sum;
        }
        //======================
        sum = 0;
        for(int i=3*n-1;i>=2*n;i--) {
            pq2.push(nums[i]);
            sum+=nums[i];
        }
        dp2[2*n] = sum;
        for(int i=2*n-1;i>=n;i--) {
            auto el = pq2.top();
            if(nums[i]>=el) {
                pq2.push(nums[i]);
                pq2.pop();
                sum += (nums[i] - el);
            }
            dp2[i] = sum;
        }
        long long ans = (long long)1e10;
        for(int i=n-1;i<2*n;i++) {
            ans = min(ans, dp[i]-dp2[i+1]);
        }
        return ans;
    }
};