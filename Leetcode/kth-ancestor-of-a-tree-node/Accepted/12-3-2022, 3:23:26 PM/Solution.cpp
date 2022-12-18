// https://leetcode.com/problems/kth-ancestor-of-a-tree-node

class TreeAncestor {
public:
    vector<vector<int>> adj;
    vector<vector<int>> ances;
    vector<int> depth;

    void dfs(int s, int par, int curr_depth) {
        ances[s][0] = par;
        depth[s] = curr_depth;

        for(int i=1;i<20;i++) {
            int anc = ances[s][i-1];
            ances[s][i] = ances[anc][i-1];
        }
        
        for(auto &x: adj[s]) {
            dfs(x, s, curr_depth+1);
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        adj.assign(n, vector<int> ());
        depth.assign(n, 0);
        ances.assign(n, vector<int> (20, 0));

        for(int i=1;i<n;i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, 0, 0);
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node]<k) {
            return -1;
        }
        for(int i=19;i>=0;i--) {
            if(1<<i <= k) {
                node = ances[node][i];       
                k-=(1<<i);
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */