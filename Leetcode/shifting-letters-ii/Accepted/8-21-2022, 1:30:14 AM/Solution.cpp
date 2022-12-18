// https://leetcode.com/problems/shifting-letters-ii

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        string ans;
        vector<int> res(n+1, 0);
        for(auto &x: shifts) {
            int start = x[0];
            int end = x[1];
            int dir = x[2];
            if(dir) {
                res[start]++;
                res[end+1]--;
            } else {
                res[start]--;
                res[end+1]++;
            }
        }
        for(int i=1;i<=n;i++) {
            res[i] = (res[i-1]+res[i]);
        }
        for(int i=0;i<n;i++) {
            int ch = s[i]-'a';
            ch = ((ch+res[i])%26 + 26)%26;
            ans += ('a'+ch);
        }
        return ans;
    }
};