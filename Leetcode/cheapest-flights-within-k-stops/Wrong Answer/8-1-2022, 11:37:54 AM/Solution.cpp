// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    #define pii pair<int,int>
    // struct node {
    //     int dis,stops,city;
    //     node(int dis, int stops, int city) {
    //         this->dis = dis;
    //         this->stops = stops;
    //         this->city = city;
    //     }
    //     bool operator >(node const &a) {
    //         if(dis!=a.dis) {
    //             return  dis<a.dis;
    //         } else {
    //             return stops < a.stops;
    //         }
    //     }
    // };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<flights.size();i++) {
            int a = flights[i][0];
            int b = flights[i][1];
            int dis = flights[i][2];
            adj[a].push_back({b, dis});
        }
        vector<int> vis(n, 0);
        vector<int> dis(n, -1);
        priority_queue <pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
        pq.push({0, {0, src}});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int city = top.second.second;
            int disttill = top.first;
            int stops = top.second.first;
            
            if(!vis[city]) {
                vis[city] = 1;
                dis[city] = disttill;
                if(stops<=k) {
                    for(auto &x: adj[city]) {
                        pq.push({disttill+x.second, {stops+1, x.first}});
                    }
                }
            }
        }
        // for(int i=0;i<n;i++) {
        //     cout<<dis[i]<<" ";
        // }
        // cout<<endl;
        return dis[dst];
        
    }
};