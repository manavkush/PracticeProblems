// https://leetcode.com/problems/task-scheduler-ii

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int k) {
        set<vector<int>> st;
        int n = tasks.size();
        int ans = 0;
        map<int,int> hash;
        int curr = 0;
        for(int i=0;i<n;i++) {
            int task = tasks[i];
            if(hash[task]<=curr) {
                hash[task] = curr+k+1;
                curr++;
            } else {
                curr += hash[task]-curr+1;
                hash[task] += k+1;
            }
        }
        return curr;
    }
};