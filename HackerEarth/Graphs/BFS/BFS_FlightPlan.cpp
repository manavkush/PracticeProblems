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

const int N=1e3+1;
vector<int> adj[N];
bool vis[N]={false};
int n,m,t,c;
vector<int> pre(N);

void bfs(int x, int y)
{
    queue<int> q;
    q.push(x);
    vis[x]=true;
    pre[x]=-1;

    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(auto x:adj[top])
        {
            if(!vis[x])
            {
                vis[x]=true;
                pre[x]=top;
                q.push(x);
            }
        }
        
    }
}

int main()
{
    FIO;
    cin>>n>>m>>t>>c;
    re(i,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    re(i,n)
        sort(adj[i].begin(),adj[i].end());
    int x,y;
    cin>>x>>y;
    bfs(x,y);
    re(i,n)
    {
        cout<<i<<": ";
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    int p=y;
    vi arr;
    arr.push_back(p);
    while(pre[p]!=-1)
    {
        p=pre[p];
        arr.push_back(p);
    }
    reverse(arr.begin(),arr.end());
    cout<<arr.size()<<endl;
    for(auto x:arr)
    {
        cout<<x<<" ";
    }

}