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
        if(curr>=k) {
            return ans;
        } else {
            for(;curr<k;curr++) {
                ans.pop_back();
            }
        }
        return ans;
        
    }
};