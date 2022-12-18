// https://leetcode.com/problems/generate-parentheses

class Solution {
private:
    void util(int n, string &curr, vector<string> &ans, int sum) {
        if(n==0) {
            if(sum==0) {
                ans.push_back(curr);
            } 
            return;
        } 
        curr += "(";
        util(n-1, curr, ans, sum+1);
        curr.pop_back();
        
        if(sum>0) {
            curr+= ")";
            util(n-1, curr, ans, sum-1);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        int sum = 0;
        util(2*n, curr, ans, sum);
        return ans;
    }
};