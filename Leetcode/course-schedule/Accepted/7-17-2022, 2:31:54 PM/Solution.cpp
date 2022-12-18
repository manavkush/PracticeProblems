// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &x: prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        vector<int> indegree(numCourses, 0);
        for(auto &x: prerequisites) {
            indegree[x[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            cnt++;
            for(auto &x: adj[top]) {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        return (cnt==numCourses);
    }
};