// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
private:
    int util(vector<vector<int>> &adj, int n, int node, int myrank, vector<int> &ranks, vector<vector<int>> &result ) {
        if(ranks[node] != -2) // Already visited the node
            return ranks[node];
        
        ranks[node] = myrank;
        int lowest_rank = myrank;
        
        for(auto &neigh: adj[node]) {
            if(ranks[neigh]==myrank-1)    // Parent
                continue;
            if(ranks[neigh]==n) 
                continue;
            /* We've done the neigh earlier.
                So node is the ancestor of neigh.
                So neigh -> node is a back edge
            */
            int ret_rank = util(adj, n, neigh, myrank+1, ranks, result);
            lowest_rank = min(lowest_rank, ret_rank);
            if(ret_rank > myrank) {
                result.push_back({node, neigh});
            }
        }
        ranks[node] = n;
        return lowest_rank;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &x: connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<vector<int>> result;
        vector<int> ranks(n, -2);
        util(adj, n, 0, 0, ranks, result);
        return result;
    }
};