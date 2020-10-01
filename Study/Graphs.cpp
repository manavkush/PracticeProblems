#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
/*
        Pseudo code to implement dfs
        n = number of nodes in graph
        g= adjacency list representing the graph
        visited=[false,false,.....] (n elements)
        void dfs(at)
        {
                if (visited[at])  return
                visited[at]=true

                ls = g[at]
                for i in ls:
                        dfs(i)
        }
*/
void addEdge(vector<int>adj[],int u,int v)
{
        adj[u].push_back(v);
        adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int n)
{
        re(i,n)
        {
                cout<<"Adjacency List  "<<i<<" ";
                for(auto x:adj[i])
                        cout<<x<<" ";
                cout<<endl;
        }
}

int main()
{
        FASTIO;
        vi adj[5];
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 4);
        addEdge(adj, 1, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 1, 4);
        addEdge(adj, 2, 3);
        addEdge(adj, 3, 4);
        printGraph(adj,5);
}
