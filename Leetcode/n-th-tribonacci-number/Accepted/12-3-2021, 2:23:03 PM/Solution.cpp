// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
private:
    map<int,int> dp = {};
public:
    int tribonacci(int n) {
        if(n==0)    return 0;
        if(n==1)    return 1;
        if(n==2)    return 1;
        if(dp.find(n)==dp.end()) {
            dp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        }
        return dp[n];
    }
};