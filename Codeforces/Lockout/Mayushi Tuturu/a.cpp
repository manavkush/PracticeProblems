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
const int N = 1e5+4;
int n,m;
vector<int> npeeps; // stores no of people passing through that city
vector<int> adj[N];
vector<int> vis;
vector<int> happy(N,0);     // No of happy people passing through a city
vector<int> sad(N,0);       // No of sad people passing through a city
vi p;   // citizens in each city
vi h;   // Happiness index of each city

void dfs(int node) {    // Gets the number of people passing through a certain city
    npeeps[node] = p[node];
    for(auto x: adj[node]) {
        if(!vis[x]) {
            vis[x]=1;
            dfs(x);
            npeeps[node]+=npeeps[x];
        }
    }
}

bool check(int node,int pvalue) {
    if(happy[node]>pvalue) {
        return false;
    } else {
        int goods,bads;
        goods=bads=0;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                vis[x]=1;
                if(!check(x,happy[node]))
                    return false;
                goods+=happy[x];
                // bads+=sad[x];
            }
        }
        if(goods>happy[node]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin>>n>>m;

    re(i,n+1) {
        adj[i].clear();
    }
    p.clear();
    h.clear();
    happy.clear();
    sad.clear();
    vis.clear();
    npeeps.clear();

    
    p.resize(n+1,0);
    h.resize(n+1,0);    
    vis.resize(n+1,0);

    // Now For storing recursive information
    npeeps.resize(n+1,0);
    happy.resize(n+1,0);
    sad.resize(n+1,0);

    re1(i,1,n) {    // People living in each city
        cin>>p[i];
    }
    re1(i,1,n) {    // Happiness index of each city
        cin>>h[i];
    }
    re(i,n-1) {  // Taking graph as input
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vis[1]=1;
    dfs(1);
    bool ans=true;
    // making the happy and sad array
    re1(i,1,n) {
        if(abs(npeeps[i]-h[i])&1) {
            ans=false;
            break;
        }
        happy[i] = (npeeps[i]+h[i])/2;
        sad[i] = (npeeps[i]-h[i])/2;
    }
    if(!ans) {
        cout<<"NO\n";
        return;
    }
    
    vis.clear();
    vis.resize(n+1,0);
    vis[1]=1;
    if(!check(1,INT_MAX)) {
        cout<<"NO\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        if(abs(h[i])>npeeps[i]) {
            cout<<"NO\n";
            return;
        }
    }

    if(ans) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}

int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}