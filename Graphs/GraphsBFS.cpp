#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool visited[N];
vector<int>adj[N];

void addedge(int u,int v)
{
        adj[u].push_back(v);
}

void bfs(int s)
{
        queue<int> q;
        q.push(s);
        visited[s]=true;
        while (!q.empty())
        {
                cout<<q.front()<<" ";
                for(auto x: adj[q.front()])
                {
                        if(!visited[x])
                        {
                                q.push(x);
                                visited[x]=true;
                        }
                }
                q.pop();
        }       
}

int main()
{
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                int u,v;
                cin>>u>>v;
                addedge(u,v);
        }
        int s;
        cin>>s;
        bfs(s);
}