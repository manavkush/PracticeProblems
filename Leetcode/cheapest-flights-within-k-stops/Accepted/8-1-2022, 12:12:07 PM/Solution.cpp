// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    #define pii pair<int,int>
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<flights.size();i++) {
            int a = flights[i][0];
            int b = flights[i][1];
            int dis = flights[i][2];
            adj[a].push_back({b, dis});
        }
        vector<int> dis(n, INT_MAX);
        priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, 0, src});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int disttill = top[0];
            int stops = top[1];
            int city = top[2];
            
            if(city == dst)
                return disttill;
            if(dis[city]<stops) continue;
            dis[city] = stops;
            
            if(stops<=k) {
                for(auto &next: adj[city]) {
                    pq.push({disttill+ next.second, stops+1, next.first});
                }
            }
            
        }
        
        return -1;
        
    }
};