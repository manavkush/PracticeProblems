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
const int N = 1e5+5;
vector<int> adj[N];
vector<int> vis(N,0);
map<int,int> parent;

int first=-1, last=-1;
bool find_cycles() {

}

bool dfs(int s, int par) {  // True if cycle present
    vis[s] = 2;
    for(auto x: adj[s]) {
        if(x==par) continue;
        if(vis[x]==0) {
            parent[x] = s;
            vis[x] = 2;
            if(dfs(x, s)) {
                return true;
            }
        } else if(vis[x] == 2) {    // Currently visiting
            first = x;
            last = s;
            return true;
        }
    }
    vis[s] = 1;
    return false;
}

int32_t main()
{
    FIO;
    int n,m;
    cin>>n>>m;
    while(m--) {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++) {
        if((vis[i] == 0 ) and dfs(i, -1)) {
            break;
        }
    }
    if(first == -1) {
        cout<<"IMPOSSIBLE";
    } else {
        int curr = last;
        vector<int> res;
        res.pb(first);
        while(curr!=first) {
            res.pb(curr);
            curr = parent[curr];
        }
        res.pb(first);
        cout<<res.size()<<endl;
        for(auto x: res) {
            cout<<x<<" ";
        }
    }
}