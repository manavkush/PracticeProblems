// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

class Solution {
private:
    bool check(vector<int> &candies, int number, long long k) {
        long long ans = 0;
        for(auto &x: candies) {
            ans += (x/number);
        }
        return ans >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = 1e7+1;
        while(l+1<r) {
            int mid = (l+r)/2;
            if( check(candies, mid, k) ) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};