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
        st.insert({1.0, start});
        cout<<setprecision(8)<<endl;
        vector<double> dist(n, 0);
        while(!st.empty()) {
            pair<double, int> top = *st.begin();
            dist[top.second] = top.first;
            st.erase(st.begin());
            for(auto x: adj[top.second]) {
                if(top.first * x.second > dist[x.first]) {
                    dist[x.first] = top.first * x.second;
                    st.insert({ top.first * x.second, x.first});
                }
            }
        }
        return dist[end];
    }
};