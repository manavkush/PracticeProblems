// https://leetcode.com/problems/course-schedule

class Solution {
private:
    bool check_cycle(vector<vector<int>> &adj, vector<int> &vis, int sc ) {
        vis[sc] = 2;    // currently visiting
        for(auto x: adj[sc]) {
            if(!vis[x]) {
                if(check_cycle(adj, vis, x))
                    return true;
            } else if(vis[x]==2) {
                return true;
            }
        }
        vis[sc] = 1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &x: prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                if(check_cycle(adj, vis, i))
                    return false;
            }
        }
        return true;
    }
};