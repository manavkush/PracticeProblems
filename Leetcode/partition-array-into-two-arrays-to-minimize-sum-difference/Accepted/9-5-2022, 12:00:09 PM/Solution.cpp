// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<int>> left(n+1), right(n+1);
        
        for(int mask=0; mask<(1<<n); mask++) {
            int sz = 0, l = 0, r = 0;
            for(int j=0;j<n;j++) {
                if(mask&(1<<j)) {
                    sz++;
                    l+= nums[j];
                    r+= nums[n+j];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = min(abs(total-2*left[n][0]), abs(total-2*right[n][0])); // Either: all on left/ all on right
        
        for(int sz=0; sz<=n; sz++) {
            sort(right[sz].begin(), right[sz].end());
        }
        // cout<<ans<<endl;
        for(int lsz = 1; lsz < n; lsz++) {
            int rsz = n-lsz;
            auto &r = right[rsz];
            for(auto &lsum : left[lsz]) {
                int rwant = (total-2*lsum)/2;
                auto itr = lower_bound(r.begin(), r.end(), rwant);
                if(itr!=r.end()) {
                    int rsum = *itr;
                    ans = min(ans, abs(total-2*(lsum+rsum)));
                }
                if(itr!=r.begin()) {
                    int rsum = *(--itr);
                    ans = min(ans, abs(total-2*(lsum+rsum)));
                }
            }
        }
        
        return ans;
    }
};