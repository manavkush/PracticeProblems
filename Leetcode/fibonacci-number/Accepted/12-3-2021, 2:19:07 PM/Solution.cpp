// https://leetcode.com/problems/fibonacci-number

class Solution {
    private:
    map<int,int> dp;
    public:
    
    int fib(int n) {
        if(n==0)   return 0;
        if(n==1)    return 1;
        if(dp.find(n)==dp.end()) {
            dp[n] = (fib(n-1)+fib(n-2));
        }
        return dp[n];
    }
};