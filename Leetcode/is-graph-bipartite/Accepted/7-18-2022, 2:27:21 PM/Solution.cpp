// https://leetcode.com/problems/is-graph-bipartite

class Solution {
private:
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, int s, int col) {
        vis[s] = col;
        for(auto &x: adj[s]) {
            if(vis[x]==0) {
                if(!dfs(adj, vis, x, ((col-1)^1)+1))
                    return false;
            } else if(vis[x]==vis[s]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                if(!dfs(graph, vis, i, 1)) {
                    return false;
                }
            }
        }
        for(auto x: vis) {
            cout<<x<<" ";
        }
        return true;
    }
    
};