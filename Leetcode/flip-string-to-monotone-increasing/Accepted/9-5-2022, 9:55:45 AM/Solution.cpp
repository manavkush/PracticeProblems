// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cnt += (s[i]-'0');
        }
        int ans = n-cnt;
        int curr = 0;
        for(int i=0;i<n;i++) {
            curr += (s[i]-'0');
            ans = min(ans, curr + (n-1-i)-(cnt-curr));
        }
        return ans;
    }
};