// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n);
        
        int i=0, j = 1;
        
        while(j<n) {
            if(s[i]==s[j]) {
                lps[j] = i+1; 
                i++, j++;
            } else {
                if(i==0) {
                    j++;
                } else {
                    i = lps[i-1];
                }
            }
        }
        int max_len = 0;
        int max_idx = -1;
        
        for(int i=0;i<n;i++) {
            if(lps[i]>max_len) {
                max_len = lps[i];
                max_idx = i;
            }
        }
        // for(auto &x: lps) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        return s.substr(0, max_len);
        
    }
};