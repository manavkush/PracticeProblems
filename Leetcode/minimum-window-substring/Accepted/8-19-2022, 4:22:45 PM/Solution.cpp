// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> hs, ht;
        // for(auto &x: s) {
        //     hs[x]++;
        // }
        for(auto &x: t) {
            ht[x]++;
        }
        int l = 0;
        int n = s.length();
        string ans = s;
        int anslen = INT_MAX;
        for(int r=0;r<n;r++) {
            hs[s[r]]++;
            bool flag = 0;
            for(auto &x: ht) {
                if(hs[x.first]<x.second) {
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                continue;
            }
            while(hs[s[l]]>ht[s[l]]) {
                hs[s[l]]--;
                l++;
            }
            if(anslen>r-l+1) {
                ans = s.substr(l, r-l+1);
                anslen = r-l+1;
            }
        }
        return anslen == INT_MAX ? "" : ans;
    }
};