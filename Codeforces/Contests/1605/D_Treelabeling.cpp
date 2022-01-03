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
const int N = 2e5+5;
vector<int> msb(N);     // Storing msb of each no
vector<int> ans(N);     // Final permutation
vector<int> graph[N];   // Adjacency list
vector<int> nodes[2];   // storing the nodes of each color type(b or w)

void precomput() {
    int bit = 1;
    int count = 1;
    int next = 2;
    for(int i=1;i<N;i++) {
        msb[i] = bit;
        count--;
        if(count==0) {
            bit++;
            count = next;
            next *= 2;
        }
    }
}

void dfs(int u, int par, int col) {
    nodes[col].pb(u);
    for(auto x: graph[u]) {
        if(x!= par) {
            dfs(x, u, col^1);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        graph[i].clear();
    }

    re(i,n-1) {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0, 0);
    
    vector<vector<int>> v(20);      // storing the nodes on the basis of msb
    for(int i=1;i<=n;i++) {
        v[msb[i]].pb(i);
    }

    // the max set bit would be 19 for n<=2e5
    for(int i=19;i>=0;i--) {
        int curr = 0;
        // changing the color to one having more nodes
        if(nodes[curr^1].size() > nodes[curr].size()) {
            curr ^= 1;
        }
        // for all nodes having same msb
        for(auto &it: v[i]) {
            // get a node of curr color
            int node = nodes[curr].back();
            // remove the node from the color
            nodes[curr].pop_back();
            
            ans[node] = it;
        } 
    }
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}