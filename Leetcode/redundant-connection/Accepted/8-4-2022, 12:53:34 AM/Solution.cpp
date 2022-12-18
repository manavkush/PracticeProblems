// https://leetcode.com/problems/redundant-connection

class Solution {
private:
    map<vector<int>,int> hash;
    priority_queue<pair<int,vector<int>>> cycle;
    
    void cyc_push(int x, int s) {
        vector<int> edge = {x, s};
        sort(edge.begin(), edge.end());
        cycle.push({hash[edge],edge});
    }
    bool dfs(vector<vector<int>> &adj, int s, vector<int> &vis, int par) {
        vis[s] = 1;
        for(auto &x: adj[s]) {
            if(x!=par) {
                if(vis[x]) {
                    cyc_push(x,s);
                    vis[x] = 2;
                    return true;
                } else {
                    bool ret = dfs(adj,x, vis, s);
                    if(ret) {
                        cyc_push(x, s);
                        if(vis[s]==2) {
                            return false;
                        } else {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            hash[edges[i]] = i;
        }
        vector<int> vis(n+1, 0);
        dfs(adj, 1, vis, 1);
        pair<int,vector<int>> top = cycle.top();
        return top.second;
        // return vector<int> (1, 0);
    }
};