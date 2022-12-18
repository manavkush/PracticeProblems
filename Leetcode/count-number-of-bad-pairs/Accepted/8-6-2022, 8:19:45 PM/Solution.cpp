// https://leetcode.com/problems/count-number-of-bad-pairs

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long tot = n*(n-1);
        long long ans = (n*(n-1))/2;
        map<long long,long long> hash;
        for(int i=0;i<n;i++) {
            hash[nums[i]-i]++;
        }
        for(auto &x: hash) {
            // cout<<x.first<<" "<<x.second<<endl;
            long long freq = x.second;
            ans += (freq*(freq-1)/2);
        }
        return tot-ans;
    }
};