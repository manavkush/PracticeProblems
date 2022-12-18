// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        vector<int> mat[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> res(numCourses);
        int idx = numCourses -1;
        int cnt = 0;
        
        int n = preq.size();
        for(int i=0;i<n;i++) {
            mat[preq[i][0]].push_back(preq[i][1]);
            indegree[preq[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int top = q.front();
            cnt ++;
            q.pop();
            
            for(auto x: mat[top]) {
                indegree[x]--;
                if(!indegree[x]) q.push(x);
            }
            res[idx] = (top);
            idx--;
        }
        if(cnt == numCourses) {
            // reverse(res.begin(), res.end());
            return res;
        } else {
            return vector<int> ();
        }
    }
};