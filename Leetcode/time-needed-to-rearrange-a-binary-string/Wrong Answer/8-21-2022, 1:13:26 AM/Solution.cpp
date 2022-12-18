// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0;
        int n = s.length();
        int ans = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') {
                cnt++;
                ans = max(ans, n-i-cnt);
            }
        }
        return ans;
    }
};