// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mat(numCourses);
        
        for(auto x: prerequisites) {
            mat[x[0]].push_back(x[1]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses; i++) {
            for(auto x: mat[i]) {
                indegree[x]++;
            }
        }
        for(int j=0;j<numCourses; j++) {
            int i= 0;
            for(i=0;i<numCourses && indegree[i]!=0;i++);
            if(i==numCourses) {
                return false;
            }
            for(auto x: mat[i]) {
                indegree[x]--;
            }
        }
        
        return true;
    }
};