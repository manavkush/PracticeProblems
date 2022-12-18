// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int, double>> adj[n];
        
        // Creating adjacency list
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back( {edges[i][1], succProb[i]} );
        }
        
        
        set<pair<int,double>> st;
        st.insert({start, 1.0});
        cout<<setprecision(8)<<endl;
        vector<double> dist(n, 0);
        while(!st.empty()) {
            pair<int, double> top = *st.begin();
            dist[top.first] = top.second;
            st.erase(st.begin());
            for(auto x: adj[top.first]) {
                if(top.second * x.second > dist[x.first]) {
                    dist[x.first] = top.second * x.second;
                    st.insert({x.first, top.second * x.second});
                }
            }
        }
        return dist[end];
    }
};