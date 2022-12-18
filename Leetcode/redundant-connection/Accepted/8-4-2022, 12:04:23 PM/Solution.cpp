// https://leetcode.com/problems/redundant-connection

class Solution {
private:
    int find(vector<int> &parent, int u) {
        if(parent[u]!=u) {
            parent[u] = find(parent, parent[u]);
        }
        return parent[u];
    }
    void _union(vector<int> &parent,vector<int>&rank, int u, int v) {
        u = find(parent, u);
        v = find(parent, v);
        if(rank[u]==rank[v]) {
            parent[v] = u;
            rank[u]++;
        } else if(rank[u]>rank[v]) {
            parent[v] = u;
        } else {
            parent[u] = v;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> parent(n, 0);
        vector<int> rank(n,0);
        
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
        
        for(int i=0;i<n;i++) {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            if(find(parent,u)==find(parent,v)) {
                return edges[i];
            } else {
                _union(parent, rank, u, v);
            }
        }
        return vector<int>(2, 0);
    }
};