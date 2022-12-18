// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
private: 
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, int s) {
        
        vis[s] = 1;
        for(auto &x: graph[s]) {
            if((vis[x]==0 && dfs(graph, vis, x)) || vis[x]==1) {
                return true;
            }
        }
        vis[s] = 2;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
            if(vis[i]==2 || (!dfs(graph, vis, i))) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};