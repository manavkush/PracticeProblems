// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto x: nums) {
            hash[x]++;
        }
        int ans = 0;

        for(auto x: nums) {
            if(hash.find(x-1)==hash.end()) {
                int curr = x+1;
                while(hash.find(curr)!=hash.end()) {
                    curr++;
                }
                ans = max(ans, curr-x);
            }
        }
        return ans;
    }
};