#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void dfs(int sc, vector<int>& vis, vector<vector<int>> adj) {
    // cout<<"*";
    vis[sc] = cnt;
    for(auto x: adj[sc]) {
        if(!vis[x]) {
            vis[x] = cnt;
            dfs(x, vis, adj);
        }
    }
}

int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    for(int i=1; i<=n;i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i, vis, adj);
        }
    }
    cout<<cnt<<endl;
    // return cnt;
}