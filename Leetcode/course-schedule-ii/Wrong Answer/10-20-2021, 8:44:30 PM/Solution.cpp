// https://leetcode.com/problems/course-schedule-ii

class Solution {
private: 
    void dfs(int sc, vector<vector<int>> &mat, vector<int> &res, vector<bool> &vis) {
        vis[sc] = 1;
        for(auto x: mat[sc]) {
            if(!vis[x]) {
                vis[x] = 1;
                dfs(x, mat, res, vis);
            }
        }
        res.push_back(sc);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, 0);
        vector<vector<int>> mat(numCourses);
        for(auto x: prerequisites) {
            mat[x[0]].push_back(x[1]);
            vis[x[0]] = 1;
            if(vis[x[1]]) {
                return vector<int>();
            } else {
                continue;
            }
        }
        vector<int> res;
        for(int i=0;i<numCourses; i++) {
            vis[i] = 0;
        }
        
        for(int i=0;i<numCourses;i++) {
            dfs(i, mat, res, vis);
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};