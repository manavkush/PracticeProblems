// https://leetcode.com/problems/is-graph-bipartite

class Solution {
private:
    bool bfs(vector<vector<int>> &adj, vector<int> &vis, int s) {
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            for(auto &x: adj[top]) {
                if(!vis[x]) {
                    if(vis[top]==1)
                        vis[x] = 2;
                    else 
                        vis[x] = 1;
                    q.push(vis[x]);
                } else if(vis[x]==vis[top]) {
                    return false;
                }
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
                if(!bfs(graph, vis, i))
                    return false;
            }
        }
        return true;
    }
    
};