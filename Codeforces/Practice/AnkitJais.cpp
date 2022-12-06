#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<bool> vis(n+1, 0);
    int ans = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int node = top.second;
        int dis = top.first;
        if(vis[node]) {
            continue;
        }
        vis[node] = 1;
        ans += dis;
        for(auto &x: adj[node]) {
            if(!vis[x.first])
            pq.push({x.second, x.first});
        }
    }
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            cout<<"Need More Dealers\n";
            return;
        }
    }
    cout<<ans<<endl;
}

int main(void)
{    
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}

/*********************MAIN PROGRAM*************************/