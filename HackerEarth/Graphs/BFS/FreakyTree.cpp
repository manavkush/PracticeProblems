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
    int V;
    vector<pair<int,int> >*adj;     // To store the destination edge and the weight
    int *vis;
    public:
    Graph(int V);           //Constructor
    void addedge(int u,int v,int w);  //Adding an edge
    void print();
    int bfs();
};
Graph::Graph(int V)
{
    this->V=V;
    adj = new vector<pair<int,int> > [V];      //Intializing the adjacency list
    vis = new int [V];
}
void Graph::addedge(int u,int v,int w)
{
    adj[u].push_back(mp(v,w));
    adj[v].push_back(mp(u,w));
}
void Graph::print()
{
    re(i,V)
    {
        cout<<i<<": ";
        for(auto x:adj[i])
        {
            cout<<x.first<<","<<x.second<<"  ";
        }
        cout<<endl;
    }
}
int Graph::bfs()
{
    int count=0;
    re(i,V)
        vis[i]={-1};
    queue<int> q;
    q.push(1);
    vis[1]=2;
    while(!q.empty())
    {
        bool leaf=true;
        int top=q.front();
        q.pop();
        for(auto x:adj[top])
        {
            if(vis[x.first]!=-1)
                continue;
            if(top==1)
            {
                vis[x.first]=x.second;
                q.push(x.first);
                leaf=false;
            }
            else
            {
                vis[x.first]=x.second^vis[top];
                q.push(x.first);
                leaf=false;
            }
        }
        if(leaf)
        {
            //deb(top);
            if(vis[top])
                count++;
        }
    }
    return count;
}
 
//==========================================GRAPH CLASS=====================================
 
int main()
{
    FIO;
    int t;
    cin>>t;
    re(i,t)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<0<<endl; continue;
        }
        Graph g(n+1);
        re(j,n-1)
        {
            int a,b,c;
            cin>>a>>b>>c;
            g.addedge(a,b,c);
        }
        //cout<<"#\n";
        //g.print();
        cout<<g.bfs()<<endl;
 
    }
    
}
