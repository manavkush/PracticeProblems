// https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    void dfs(int val, int n,vector<int>&ans) {
        if(val>n)return;
        ans.push_back(val);
        for(int i=0;i<=9;i++) {
            dfs(10*val+i, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++) {
            dfs(i, n, ans);
        }
        return ans;
    }
};