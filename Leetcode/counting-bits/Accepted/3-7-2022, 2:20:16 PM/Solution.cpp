// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=0;i<=n;i++) {
            int num = i;
            int count = 0;
            
            if(num&1)
                ans[i] = 1+ans[i/2];
            else 
                ans[i] = ans[i/2];
            
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};