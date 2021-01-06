// Author: manavkush
// Date: 04/01/2021

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
const int N=2e5+5;
vector<int> adj[N];
vector<int> dp; // lowest distance possible to achieve
vector<int> depth;
vector<bool> vis;

// First found the minimum distance from the root node to all the other nodes using bfs
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    depth[s]=0;

    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(auto x:adj[top])
        {
            if(depth[x]==-1)
            {
                depth[x]=depth[top]+1;
                q.push(x);
            }
        }
    }
}

int dfs(int s) {
    if(vis[s]) {
        return dp[s];
    }
    vis[s]=1;
    dp[s]=depth[s];
    for(auto x:adj[s]) {
        dp[s]=min(dp[s],depth[x]);  // Backedge case
        if(depth[x]>depth[s]) {
            dfs(x);
            dp[s]=min(dp[s],dp[x]);
        }
    }
    debug(s,dp);
    return dp[s];
}


int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        // memset(dp,INT_MAX,sizeof(dp));
        vis.resize(n+1);
        depth.resize(n+1,-1);
        dp.resize(n+1,INT_MAX);
        re(i,m) {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
        }
        bfs(1);
        
        // cout<<endl<<"Dis: ";
        // re1(i,1,n) {
        //     cout<<depth[i]<<" ";
        // } cout<<endl;

        dfs(1);
        // for(int i=1;i<=n;i++) {
        //     dfs(i);
        // }
        for(int i=1;i<=n;i++) {
            cout<<dp[i]<<" ";
        }
        cout<<endl;


        for(auto &v: adj) {
            v.clear();
        }
        vis.clear();
        depth.clear();
        dp.clear();
    }
}
