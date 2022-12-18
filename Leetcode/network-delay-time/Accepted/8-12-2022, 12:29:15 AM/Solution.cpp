// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &x: times) {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
        }
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        
        set<pair<int,int>> st;
        st.insert({0, k});
        
        while(!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());
            
            int dis = top.first, node = top.second;
            distance[node] = dis;
            
            for(auto &x: adj[node]) {
                int next = x.first, dx = x.second;
                
                if(distance[next] > dis + dx) {
                    
                    auto pos = st.find({distance[next], next});
                    if(pos!=st.end())
                        st.erase(pos);
                    
                    st.insert({dis+dx, next});
                    distance[next] = dis+dx;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = max(ans, distance[i]);
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};