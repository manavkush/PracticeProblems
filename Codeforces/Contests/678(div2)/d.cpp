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
vector<int> adj[N];     // Adjacency list
vector<int> a(N,0);     // Stores the citizens in all cities
vector<int> sum(N,0);   // Stores the sum of all citizens of the subtrees and itself
vector<int> nleaves(N,0);   // No of leaves contained in the subtree of a node
vector<int> dp(N,0);        // The answer to the subtree of ith node

// We do a dfs
// There are two ways. 1)To distribute evenly (ceil(sum)/leaves)
// Distributing such that 2) Maximum child doesn't change.

void dfs(int node) {
    sum[node]=a[node];  // We'll store no of citizens in the subtree of this node.
    dp[node] = 0;       // Stores the maximum citizens that the burglar can catch starting from node: "node"
    for(auto x: adj[node]) {
        {
            dfs(x);
            sum[node]+=sum[x];
            nleaves[node] += nleaves[x];
            dp[node] = max(dp[x],dp[node]);
        }
    }
    if(adj[node].size()==0) {   // If it is a leaf node
        nleaves[node]=1;
        sum[node] = a[node];
        dp[node] = a[node];
        return ;
    }
    dp[node] = max((sum[node]+nleaves[node]-1)/nleaves[node],dp[node]);
    return ;
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
<<<<<<< HEAD
        vector<int> p(n);
        re1(i,2,n) {
            cin>>p[i];
            adj[p[i]].pb(i);
=======
        re1(i,2,n) {
            int p;
            cin>>p;
            adj[p].pb(i);
>>>>>>> 006b84d6056b6bb90a1359dfd1542a8b77ed57af
        }
        re1(i,1,n) {
            cin>>a[i];
        }
<<<<<<< HEAD
=======
        dfs(1);
        cout<<dp[1]<<endl;
>>>>>>> 006b84d6056b6bb90a1359dfd1542a8b77ed57af
    }
}