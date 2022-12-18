// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int, double>> adj[n];
        
        // Creating adjacency list
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back( {edges[i][1], succProb[i]} );
        }
        
        
        set<pair<double,int>> st;
        vector<double> dist(n, 0);
        
        st.insert({1.0, start});
        dist[start] = 1.0;
        
        cout<<setprecision(8)<<endl;
        while(!st.empty()) {
            auto top = *st.begin();
            double dis = top.first;
            int id = top.second;
            st.erase(st.begin());
            // cout<<dis<<" "<<id<<endl;
            
            for(auto x: adj[id]) {
                if(dis*x.second > dist[x.first] ) {
                    auto f = st.find({dist[x.first], x.first});
                    if(f!=st.end()) {
                        st.erase(f);
                    }
                    dist[x.first] = dis*x.second;
                    st.insert({dist[x.first], x.first});
                }
            }
        }
        return dist[end];
    }
};