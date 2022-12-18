// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans;
        int curr = 0;
        for(int i=0;i<n;i++) {
            if(curr>=k || i==n-1 || num[i]<=num[i+1]) {
                ans += num[i];
                continue;
            }
            curr++;
        }
        
        if(curr<k) {
            for(;curr<k;curr++) {
                ans.pop_back();
            }
        }
        int start = 0;
        for(start=0;start<ans.length();start++) {
            if(ans[start]!='0') {
                break;
            }
        }
        if(start==ans.length()) {
            return "0";
        }
        return ans.substr(start);
        
    }
};