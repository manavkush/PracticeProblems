// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

class Solution {
private:
    int util(vector<int> &a, vector<int>&dp, int i, int n) {
        if(i>=n)
            return 1;

        if(dp[i]!=-1)
            return dp[i];
        
        int con1=0, con2=0, con3=0;
        
        if(n-i>1) { // 
            if(a[i]==a[i+1]) {
                con1 = util(a, dp, i+2, n);
                if(con1)
                    return dp[i] = 1;
            }
        }
        
        if(n-i>2) {
            if(a[i]==a[i+1] and a[i+2]==a[i]) {
                con2 = util(a, dp, i+3,n);
                if(con2)
                    return dp[i] = 1;
            }
            
            if(a[i+1]==a[i]+1 and a[i+2] == a[i]+2) {
                con3 = util(a, dp, i+3, n);
                if(con3)
                    return dp[i] = 1;
            }
            
        }
        
        return dp[i] = 0;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return util(nums,dp,0, n);
    }
};