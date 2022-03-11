// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

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
vector<vector<pii>> adj;
int ans = 0;

void dfs(int s, vector<int> &vis, int curr) {
    vis[s] = 1;
    // debug(vis);
    for(auto x: adj[s]) {
        if(vis[x.ff] ==0 and ((x.ss & curr) <= ans)) {
            dfs(x.ff, vis, curr);
        }
            // cout<<"*";
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    adj.assign(n+1, vector<pii> ());
    re(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    ans = 0;
    for(int i=0;i<30;i++) {
        ans = (ans + (1<<i));
        // debug(ans);
    }
    int curr = 0;

    for(int i=29;i>=0;i--) {
        curr = curr + (1<<i);
        vector<int> vis(n+1, 0);
        // for(int j=29;j>=0;j--) {
        //     cout<<(curr&(1<<j) ? "1" : "0")<<" ";
        // }
        // cout<<endl;
        ans = ans^(1<<i);   // unsetting the bit
        for(int j=29;j>=0;j--) {
            cout<<(curr&(1<<j) ? "1" : "0")<<"";
        }
        cout<<endl;
        for(int j=29;j>=0;j--) {
            cout<<(ans&(1<<j) ? "1" : "0")<<"";
        }
        cout<<endl<<endl;
        // debug(ans);
        dfs(1, vis, curr);
        bool flag = 0;
        for(int i=0;i<n;i++) {
            if(vis[i+1]==0) {
                flag = 1;
            }
        }
        if(flag) {
            ans = ans^(1<<i);
        }
    }
    cout<<ans<<endl;
    adj.clear();
    return;
}
int32_t main()
{
    FIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();    
    }
}
