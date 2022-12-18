// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char,int> hash = {{'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.length();
        for(int i=n-1;i>=0;i--) {
            if(i==n-1) {
                ans += hash[s[i]];
            } else if(s[i]=='I' and (s[i+1]=='X'||s[i+1]=='V')) {
                ans -= 1;
            } else if(s[i]=='X' and (s[i+1]=='L'||s[i+1]=='C')) {
                ans -= 10;
            } else if(s[i]=='C' and (s[i+1]=='D'||s[i+1]=='M')) {
                ans -= 100;
            } else {
                ans+=hash[s[i]];
            }
        }
        return ans;
    }
};