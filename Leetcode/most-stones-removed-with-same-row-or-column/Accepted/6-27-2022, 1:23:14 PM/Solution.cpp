// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int idx) {
        vis[idx] = 1;
        for(auto &x: adj[idx]) {
            if(!vis[x]) {
                dfs(adj, vis, x);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int u=0;u<n;u++) {
            for(int v=u+1;v<n;v++) {
                if(stones[u][0]==stones[v][0] || stones[v][1]==stones[u][1]) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        vector<bool> vis(n, 0);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(adj, vis, i);
            }
        }
        return n-cnt;
    }
};