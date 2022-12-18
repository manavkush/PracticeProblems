// https://leetcode.com/problems/construct-smallest-number-from-di-string

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        stack<int> st;
        string ans;
        int prev = 0;
        for(int i=0;i<n;i++) {
            if(pattern[i]=='I') {
                ans += to_string(prev+1);    
                prev++;
                continue;
            }
            int cnt = 0;
            while(i<n and pattern[i]=='D') {
                cnt++;
                i++;
            }
            for(int j=0;j<cnt;j++) {
                ans += to_string(prev+cnt+1-j);
            }
            ans += to_string(prev+1);
            prev = prev+cnt+1;
        }
        return ans;
    }
};