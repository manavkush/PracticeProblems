// https://leetcode.com/problems/super-egg-drop

class Solution {
private:
    int util(int n, int k) {
        if(n==0)
            return 0;
        if(k==1)
            return n;
        if(n==1)
            return 1;
        
        return util(n/2-1, k-1)+1;
    }
public:
    int superEggDrop(int k, int n) {
        return util(n, k);
    }
};