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
const int N=10002;
class ret                   //  return class
{
    public:
    int fireid;
    lli kill;
    lli inj;
};
vector<int> adj[N];
vector<bool> vis(N);
vector<int> sold(N);

int dfs(int s,int maxid)
{
    vis[s]=1;
    for(auto x:adj[s])
    {
        if(vis[x])
            continue;
        vis[x]=1;
        maxid=dfs(x,maxid);
    }
    if(sold[s]>sold[maxid])
        maxid=s;
    else if(sold[s]==sold[maxid]  &&  (s<maxid))
        maxid=s;
    return maxid;
}
int main()
{
    FIO;
    int n,m;
    cin>>n>>m;
    re(i,n)
        cin>>sold[i+1];
    re(i,m)                         //  Entering the edges in adjcacency list
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans;                         
    set<int> tentid;
    lli killed=0;
    lli injured=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])                  //  Doing dfs for only those tents which have not been visited
            continue;           
        ans = dfs(i,i);
        tentid.insert(ans);              //for each defs
    }
    for(int i=1;i<=n;i++)
    {
        if(tentid.find(i)==tentid.end())
        {
            injured+=sold[i];
        }
        else killed+=sold[i];
    }
    cout<<killed<<" "<<injured<<endl;
    for(auto x: tentid)
    {
        cout<<x<<" ";
    }
}