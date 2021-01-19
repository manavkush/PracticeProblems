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
// We'll store the maximum leaf in a subtree of a node
// We'll store the number of leaves in a subtree of a node
const int N=2e5+5;
vector<int> adj[N];
vector<int> a(N,0);
vector<int> vis(N,0);
vector<int> nleaves(N,0);
vector<int> dp(N,0);

int dfs(int node) {
    vector<int> ret;
    vis[node] = 1;
    int sum=a[node];
    int mxchild=0;
    for(auto x: adj[node]) {
        if(!vis[x]) {
            nleaves[node] += nleaves[x];
            vis[x]=1;
            int child=dfs(x);
            sum+=child;
            mxchild=max(mxchild,dp[x]);
        }
        if(adj[node].size()==0) {
            dp[node] = a[node];
        } else {
            dp[node] = max(dp[mxchild],(sum+nleaves[x]-1)/nleaves[x]);
        }
        return dp[node];
    }
}


int32_t main()
{
    FIO;
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> p(n);
        re1(i,2,n) {
            cin>>p[i];
            adj[p[i]].pb(i);
        }
        re1(i,1,n) {
            cin>>a[i];
        }
    }
}