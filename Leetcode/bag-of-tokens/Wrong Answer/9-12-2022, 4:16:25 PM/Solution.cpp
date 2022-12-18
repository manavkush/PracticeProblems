// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int l = 0, r = n-1;
        int curr = 0;
        int ans = 0;
        while(l<=r) {
            if(power<tokens[l]) {
                curr--;
                power+=tokens[r];
                r--;
            } else {
                curr++;
                power -= tokens[l];
                l++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};