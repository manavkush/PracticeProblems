#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
bool vis[N]={false};
vector<int> adj[N];

void dfs(int s)
{
    if(vis[s])
    return;
    vis[s]=true;
    for(auto x: adj[s])
        dfs(x);
}

//Distance array to store the distances of the nodes from the starting node
int dis[N];
void bfs(int s)
{
   queue <int> q;
   q.push(s);
   vis[s]=1;   dis[s]=0;

   while(!q.empty())
   {
       int top=q.front();   q.pop();
       for(auto x:adj[s])
       {
           if(vis[x])
           continue;
           vis[x]=true;       dis[x]=dis[s]+1;
           q.push(x);
       }
   }
}