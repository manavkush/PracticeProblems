// https://leetcode.com/problems/is-graph-bipartite

class Solution {
private: 
    bool dfs(int sc, int col, vector<int> &color, vector<vector<int>> &graph) {
        if(color[sc]!=-1) {
            if(color[sc]!=col)
                return false;
            else return true;
        } else {
            color[sc] = col;
            bool ans = 1;
            for(auto x: graph[sc]) {
                ans = ans && dfs(x, col^1, color, graph);
            }
            return ans;
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        bool ans = true;
        for(int i=0;i<n and ans;i++) {
            if(color[i]==-1)
                ans = ans and dfs(i, 1, color, graph);
        }
        return ans;
    }
};