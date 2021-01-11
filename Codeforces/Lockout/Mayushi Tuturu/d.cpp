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
const int N = 5e4+5;
int n,k;
vector<int> adj[N];
int dp[N][505];     // States--> Node,Distance : Gives the no of node at a distance k from the node in subtree;
int ans=0;

int dfs(int node,int par) {
    int temp=0;
    dp[node][0]=1;
    for(auto x: adj[node]) {
        if(x==par)
            continue;
        dfs(x,node);
        
        for(int i=1;i<=k;i++) {
            // Storing the no of nodes with 'i' distance from the current node in the subtree.
            dp[node][i] += dp[x][i-1]; 
        }
    }
}

void count(int node,int par) {  // this function counts the number of pairs with k distance.
    ans+=dp[node][k];   // Type 1: if the path starts at the given node.

    // type 2: When the current node lies in the middle of the path.
    int temp=0;
    for(auto x: adj[node]) {
        if(x==par) continue;
        count(x,node);
        for(int i=1;i<k;i++) {
            // We are partitioning the path like (1,k-1), (2,k-2), (3,k-3) ..;
            // The first half is in x and the rest are in the other child nodes.
            temp+=(dp[x][i-1]*(dp[node][k-i]-dp[x][k-i-1]));
        }
    }
    ans+=temp/2;    // We add half the temp as each partition is counted twice.(from both the sides: (x, neighbours),(neighbour,x))
}
int32_t main()
{
    FIO;
    // int n,k;
    cin>>n>>k;
    re(i,n-1) {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0);
    count(1,0);
    cout<<ans<<endl;
}