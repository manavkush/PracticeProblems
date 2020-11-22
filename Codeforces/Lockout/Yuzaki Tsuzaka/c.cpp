#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
const int mod = 1000000007;
//===================================DEBUG TEMPLATE=================================================
void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//====================================DEBUG TEMPLATE==============================================
int n,k;
vi *adj;
vi vis;
vi child;     // node - children
vector<pii> numchild;   // children - node (in sorted order)
vi tourist;     // If tourist or not
int res=0;      // Final answer
vi dist;        // Distances from 1

int dfs(int s,int diss)
{
    int sum=0;
    vis[s] = 1;
    dist[s] = diss;
    for(auto x:adj[s])
    {
        if(!vis[x])
        {
            sum+=dfs(x,diss+1);
        }
    }
    child[s] = sum;
    return 1+sum;
}

bool compare(pii i,pii j)
{
    if(i.ff!=j.ff)
    {
        return i.ff>j.ff;
    }
    return dist[i.ss]<dist[j.ss];
}

int32_t main()
{
    FIO;
    cin>>n>>k;
    adj = new vi [n+1];
    vis.resize(n+1,0);
    tourist.resize(n+1,0);
    dist.resize(n+1,0);
    child.resize(n+1,0);
    
    re(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    //=====================================INPUT COMPLETE====================
    dfs(1,0);
    re1(itr,1,n)
    {
        numchild.push_back(mp(child[itr],itr));
    }
    sort(all(numchild),compare);
    
    for(int i=0;i<n-k;i++)
    {
        tourist[numchild[i].second]=1;
    }
    
    vi ans;
    for(int i=1;i<=n;i++)
    {
        ans.pb(child[i]-dist[i]);
    }
    res=0;
    sort(all(ans),greater<int>());
    re(i,n-k)
    {
        res+=ans[i];
    }
    cout<<res;
}