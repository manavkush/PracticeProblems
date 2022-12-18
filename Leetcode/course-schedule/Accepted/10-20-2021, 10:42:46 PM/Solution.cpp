// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> mat[numCourses];
        int i = 0;
        int n = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        
        for(int i=0; i<n; i++) {
            mat[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        // for(int i=0;i<numCourses; i++) {
        //     for(auto x = mat[i].begin(); x!=mat[i].end(); x++) {
        //         indegree[*x]++;
        //     }
        // }
        queue<int> q;
        int cnt = 0;
        for(int i=0;i<numCourses; i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            cnt++;
            int top = q.front();
            q.pop();
            for(auto x: mat[top]) {
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
            
        }
        if(cnt==numCourses)      
        return true;
        
        return false;
    }
};