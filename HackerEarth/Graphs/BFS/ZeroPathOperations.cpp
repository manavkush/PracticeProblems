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
    vector<int>*adj;
    int *weight;
    Graph(int V);           //Constructor
    void addedge(int u,int v);  //Adding an edge
    void addweight(int u,int v);
};
Graph::Graph(int V)
{
    this->V=V;
    adj = new vector<int> [V];      //Intializing the adjacency list
    weight=new int [V];
}
void Graph::addedge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::addweight(int u,int w)
{
    weight[u]=w;
}
//==========================================GRAPH CLASS=====================================
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Graph g(n+1);
        re(i,n-1)
        {
            int a,b;
            cin>>a>>b;
            g.addedge(a,b);
        }
        re(i,n)
        {
            int a;
            cin>>a;
            g.addweight(i+1,a);
        }
        lli count=0;
        re1(i,1,n)
        {
            if(g.adj[i].size()<=1)
                continue;
            if(g.weight[i]!=0)
            {
                g.weight[i]=0;
                count++;
            }
        }
        cout<<count<<endl;

    }
}