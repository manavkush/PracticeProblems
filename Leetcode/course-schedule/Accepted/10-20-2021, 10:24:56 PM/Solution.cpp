// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mat(numCourses);
        int i = 0;
        for(auto x: prerequisites) {
            mat[x[0]].push_back(x[1]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses; i++) {
            for(auto x = mat[i].begin(); x!=mat[i].end(); x++) {
                indegree[*x]++;
            }
        }
        for(int j=0;j<numCourses; j++) {
            
            // Finding the node with indegree 0
            for(i=0;i<numCourses && indegree[i]!=0;i++);
            
            // If not found
            if(i==numCourses) {
                return false;
            }
            // this node's indegree shouldn't be 0 now that it's considered
            indegree[i] = -1;
            for(auto x=mat[i].begin(); x!=mat[i].end(); x++) {
                indegree[*x]--;
            }
        }
        
        return true;
    }
};