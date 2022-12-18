// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++) {
            int num = i;
            int count = 0;
            while(num) {
                if(num&1)
                    count++;
                num >>= 1;
            }
            ans.push_back(count);
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};