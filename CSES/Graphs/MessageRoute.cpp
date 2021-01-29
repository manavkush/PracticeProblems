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
const int N = 1e5+ 5;
vector <int> adj[N];
bool vis[N];

int n,m;
bool flag=0;
pii start, ending;
map<int,int> parent;

vector<int> dist(N,-1);

void bfs(int s) {
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {        
        int src = q.front();
        q.pop();
        for(auto x: adj[src]) {
            if(!vis[x]) {
                vis[x] = 1;
                parent[x] = src;
                dist[x] = dist[src] + 1;
                q.push(x);
            }
        }
    }
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    re(i,m) {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dist[1] = 0;
    bfs(1);
    if(vis[n]==0) {
        cout<<"IMPOSSIBLE";
        return 0;
    } else {
        cout<<dist[n]+1<<endl;
        int curr = n;
        vector<int> path;
        while(curr!=1) {
            path.pb(curr);
            curr = parent[curr];
        }
        path.pb(1);
        reverse(all(path));
        for(auto x: path) {
            cout<<x<<" ";
        }
    }
}