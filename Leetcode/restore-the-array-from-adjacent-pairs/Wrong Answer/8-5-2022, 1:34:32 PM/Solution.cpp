// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

class Solution {
private:
    int idx = 0;
    bool done = 0;
    void dfs(unordered_map<int,vector<int>> &adj, vector<int> &ans, int par, int s) {
        if(adj[s].size()==1) {
            ans[idx] = s;
            idx++;
            return;
        }
        if(done) {
            ans[idx++] = s;
        }
        
        for(auto &x: adj[s]) {
            if(x!=par) {
                dfs(adj,ans, s, x);
                if(!done)
                    ans[idx++] = s;
                done=1;
            }
        }
        // if(adj[s].size()==1) {
        //     ans[idx] = s;
        //     idx++;
        // } else {
            
        // }
        cout<<s<<":"<<ans[idx-1]<<" ";
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int, vector<int>> adj;
        
        for(auto &x: adjacentPairs) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> ans(n+1);
        dfs(adj, ans, adjacentPairs[0][0], adjacentPairs[0][0]);
        return ans;
    }
};