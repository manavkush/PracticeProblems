// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int> &path, vector<vector<int>> &ans, int src) {
        int n = graph.size();
        path.push_back(src);
        if(src==n-1) {
            ans.push_back(path);
            path.pop_back();
        } else {
            for(auto x: graph[src]) {
                    dfs(graph, path, ans, x);
            }
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> ans;
        dfs(graph, path, ans, 0);
        return ans;
    }
};