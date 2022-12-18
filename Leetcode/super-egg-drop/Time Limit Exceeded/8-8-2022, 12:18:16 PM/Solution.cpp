// https://leetcode.com/problems/super-egg-drop

class Solution {
private:
    int util(int n, int k) {
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;
        int ans = 1e8;
        for(int i=1;i<=n;i++) {
            ans = min(ans, max(util(i-1, k-1), util(n-i, k)) + 1);
        }
        return ans;
    }
public:
    int superEggDrop(int k, int n) {
        return util(n, k);
    }
};