// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                matrix[i][j] = matrix[j][i] = dis;
            }
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n, 0);
        pq.push({0, 0});
        int ans = 0;
        
        while(!pq.empty()) {
            
            auto top = pq.top();  pq.pop();
            int node = top.second;
            int dis = top.first;
            
            if(!vis[node]) {
                // cout<<node<<":"<<dis<<" ";
                ans += dis;
                vis[node] = 1;
                for(int x=0;x<n;x++) {
                    if(vis[x]!=1) {
                        pq.push({matrix[node][x], x});
                    }
                }
            }
        }
        return ans;
    }
};