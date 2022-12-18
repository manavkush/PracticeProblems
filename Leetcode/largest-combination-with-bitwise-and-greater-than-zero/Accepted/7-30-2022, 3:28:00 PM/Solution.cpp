// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> hash(33, 0);
        int n = candidates.size();
        for(int i=0;i<n;i++) {
            int num = candidates[i];
            for(int j=0;j<31;j++) {
                if(num&(1<<j)) {
                    hash[j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<31;i++) {
            ans = max(ans, hash[i]);
        }
        return ans;
    }
};