// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<int,int>> hash(n+1);
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                int diff = A[i]-A[j];
                int curr = 1 + hash[j][diff];
                // if(hash[j].find(diff) != hash[j].end()) {
                curr = 1 + hash[j][diff];
                // }
                hash[i][diff] = max(hash[i][diff], curr);
                ans = max(ans, curr);
            }
        }
        return ans+1;
    }
};