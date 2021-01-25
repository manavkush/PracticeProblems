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
int n,m;
struct node {
    int u, v, val;
};
vector<node> adj;
vector<int> vis(2505,0);
const int MAXVAL = 1e16;


// Dijsktra
void bellman() {
    vector<int> dist(n+2, MAXVAL);
    dist[1] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            int u = adj[j].u;
            int v = adj[j].v;
            int d = adj[j].val;
            if(dist[u]>=MAXVAL)
                continue;
            if(dist[v] > dist[u]+d) {
                dist[v] = dist[u] + d;
            }
        }
        // re(i,n) {
        //     cout<<dist[i+1]<<" ";
        // }
    }
    re(i,n) {
        for(int j=0;j<m;j++) {
            int u = adj[j].u;
            int v = adj[j].v;
            int d = adj[j].val;
            if(dist[u]==MAXVAL)
                continue;
            if(dist[v] > dist[u]+d) {
                dist[v] = -MAXVAL;
            }
        }
    }
    if(dist[n]==-MAXVAL) {
        cout<<-1<<endl;
    } else
    cout<<-1*dist[n]<<endl;
    // re(i,n) {
    //     cout<<dist[i+1]<<" ";
    // }
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    re(i,m) {
        int a,b,x;
        cin>>a>>b>>x;
        adj.pb({a, b,-x});
    }
    
    bellman();  
}