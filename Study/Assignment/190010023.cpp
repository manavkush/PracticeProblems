#include<bits/stdc++.h>
using namespace std;
const int N=2002;
bool vis[N];
vector<int> adj[N];
vector<int> dist(N,0);

void addedge(int u,int v)
{
        adj[u].push_back(v);
        adj[v].push_back(u);
}

void bfs(int s)
{
        queue<int> q;
        q.push(s);
        vis[s]=true;
        int currlayer=1;
        int nextlayer=0;
        int movecount=0;
        while (!q.empty())
        {
            int top=q.front();
            q.pop();
            dist[top]=movecount;
            currlayer--;

            for(auto x:adj[top])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                    nextlayer++;
                }
            }
            if(currlayer==0)
            {
                movecount++;
                currlayer=nextlayer;
                nextlayer=0;
            }
        }
}

int main(int argc, char **argv) 
{
    string file = argv[1];
    ifstream fin;
    ofstream fout;
    fin.open(file);
    fout.open("sd.txt");

    int n,m;
    fin>>n>>m;

    for(int i=0;i<m;i++)
    {
            int u,v;
            cin>>u>>v;
            addedge(u,v);
    }
    cout<<"*";
    bfs(0);
    cout<<"*";
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            fout<<endl<<dist[i];
        }
        else
            fout<<dist[i];
    }
}