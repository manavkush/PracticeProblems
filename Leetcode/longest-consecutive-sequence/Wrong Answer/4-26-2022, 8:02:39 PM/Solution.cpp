// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> prev, next, hash;
        for(auto x: nums) {
            hash[x]++;
            prev[x]=0;
            next[x]=0;
        }
        for(auto x: nums) {
            if(hash.find(x-1)!=hash.end()) {
                prev[x] = 1;
            }
            if(hash.find(x+1)!=hash.end()) {
                next[x] = 1;
            }
        }
        int ans = 1;
        for(auto x: nums) {
            // starting from the first element
            if(prev[x]==0) {
                int cnt = 1;
                int curr = x;
                while(next[curr]==1) {
                    cnt++;
                    curr++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};