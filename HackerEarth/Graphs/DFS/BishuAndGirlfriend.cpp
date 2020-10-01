#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
//=======================================GRAPH CLASS=========================================
class Graph
{    
    public:
    int V;
    int Q;
    vector<int>*adj;
    bool *vis;
    int *gf;
    Graph(int V);           //Constructor
    void addedge(int u,int v);  //Adding an edge
    void dfs(int s);
};
Graph::Graph(int V)
{
    this->V=V;
    adj = new vector<int> [V];      //Intializing the adjacency list
    gf= new int [V];
    vis= new bool [V];
    re(i,V)
    {
        gf[i]=0;
        vis[i]=0;
    }
}

void Graph::addedge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::dfs(int s)
{
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while (!q.empty())
    {
        int top=q.front();
        q.pop();
        if(gf[top])
        {
            cout<<top;
            return;
        }
        for(auto x:adj[top])
        {
            if(!vis[x])
            {
                vis[x]=true;
                q.push(x);
            }
        }
    }
    
}
//==========================================GRAPH CLASS=====================================
int main()
{
    FIO;
    int n;
    cin>>n;
    Graph g(n+1);
    re(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        g.addedge(a,b);
        g.addedge(b,a);
    }
    int q;
    cin>>q;
    g.Q=q;
    re(i,q)
    {
        int a;
        cin>>a;
        g.gf[a]=1;
    }
    re1(i,1,n)
    {
        sort(g.adj[i].begin(),g.adj[i].end());
    }
    g.dfs(1);


}