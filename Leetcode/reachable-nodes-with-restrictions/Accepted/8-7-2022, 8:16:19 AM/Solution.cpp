// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
private:
    unordered_map<int,int> hash;
    int dfs(vector<vector<int>> &adj, int n, int s, int par) {
        // cout<<s<<" "
        if(hash.find(s)!=hash.end()) {
            return 0;
        }
        int ans = 1;
        for(auto &x: adj[s]) {
            if(x!=par) {
                ans+=dfs(adj, n, x, s);
            }
        }
        return ans;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        
        for(auto &x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(auto &x: restricted) {
            hash[x]++;
        }
        return dfs(adj, n, 0, 0);
    }
};