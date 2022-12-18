// https://leetcode.com/problems/count-number-of-bad-pairs

class Solution {
private:
    long long combinations(int n, int k) {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        long long result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long tot = n*(n-1);
        long long ans = (n*(n-1))/2;
        map<int,long long> hash;
        for(int i=0;i<n;i++) {
            hash[nums[i]-i]++;
        }
        for(auto &x: hash) {
            // cout<<x.first<<" "<<x.second<<endl;
            ans += x.second*(x.second-1)/2;
        }
        return tot-ans;
    }
};