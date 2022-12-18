// https://leetcode.com/problems/task-scheduler

class Solution {
private:
    // struct comp{
    //     bool operator() (vector<int> &a, vector<int> &b) const {
    //         if(a[0]!=b[0])
    //             return a[0]<b[0];
    //         return a[1]>=b[1];
    //     }
    // };
public:
    int leastInterval(vector<char>& tasks, int n) {
        set<vector<int>> st;
        unordered_map<char, int> hash;
        for(int i=0;i<tasks.size();i++) {
            hash[tasks[i]]++;
        }
        for(auto &x: hash) {
            vector<int> temp = {0, -x.second, x.first-'A'};
            st.insert(temp);
        }
        int time = 0;
        while(!st.empty()) {
            vector<int> temp = *st.begin();
            if(temp[0]>time) {
                time++;
                continue;
            } else {
                temp[0] += n+1;
                temp[1]++;
                st.erase(st.begin());
                if(temp[1]<0) {
                    st.insert(temp);
                }
                time++;
            }
        }
        return time;
    }
};