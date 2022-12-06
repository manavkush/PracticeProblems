#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;

/*******************DEBUG TEMPLATE*************************/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
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
/*******************DEBUG TEMPLATE*************************/

/***************MACROS AND TYPEDEFS************************/
#define tr(container, itr) for (typeof(container.begin()) itr = container.begin(); itr != container.end(); itr++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector <vector <int>> vvi;
typedef vector <vector <long long>> vvl;
#define ALL(container) container.begin(), container.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ff first
#define ss second
/****************MACROS AND TYPEDEFS***********************/

const long long MOD = 1000000007;

/******************* EXTRA FUNCTIONS *********************/
ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
 
ll MOD_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
 
ll MOD_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}

ll MOD_sub(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a - b) % MOD) + MOD) % MOD;}
 
// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 
ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}
/******************* EXTRA FUNCTIONS *********************/

/******************* EXPLANATION *************************/
/*
    
*/
/******************* EXPLANATION *************************/


/*********************MAIN PROGRAM*************************/
vector<vector<vector<int>>> adj;
vector<int> depth;
vector<vector<int>> ances;
vector<vector<int>> mins;

void dfs(int s, int cur_depth, int par, int weight) {
    depth[s] = cur_depth;
    ances[s][0] = par;
    mins[s][0] = weight;

    for(int h=1;h<20;h++) {
        ances[s][h] = ances[ances[s][h-1]][h-1];
        mins[s][h] = min( mins[s][h-1], mins[ances[s][h-1]][h-1] );
    }
    for( auto &vec: adj[s]) {
        int x = vec[0];
        int w = vec[1];
        if(x!=par) {
            dfs(x, cur_depth+1, s, w);
        }
    }
}

int kth_ances(int s, int k) {
    for(int i=19;i>=0;i--) {
        if(k>=(1<<i)) {
            s = ances[s][i];
            k -= (1<<i);
        }
    }
    return s;
}

void lca_algo(int a, int b) {
    int oga, ogb;
    oga = a, ogb = b;

    if(depth[a]<depth[b]) {
        swap(a, b);
    }
    
    a = kth_ances(a, depth[a]-depth[b]);
    
    int lca = b;
    if(a!=b) {
        for(int i=19;i>=0;i--) {
            if(ances[a][i]!=ances[b][i]) {
                a = ances[a][i];
                b = ances[b][i];
            }
        }
        lca = ances[a][0];
    }
    //------------- Found LCA ----------------------

    int ans = INT_MAX;
    for(int i=19;i>=0;i--) {
        if(depth[ances[oga][i]]>=depth[lca]) {
            ans = min(ans, mins[oga][i]);
            oga = ances[oga][i];
        }
        if(depth[ances[ogb][i]]>=depth[lca]) {
            ans = min(ans, mins[ogb][i]);
            ogb = ances[ogb][i];
        }
    }

    cout<<ans<<endl;
    
}

void solve() {
    int n, m, q;
    cin>>n>>m;
    adj.resize(n+1);
    depth.resize(n+1);
    ances.resize(n+1, vector<int> (20, 0));
    mins.resize(n+1, vector<int> (20, INT_MAX));

    for(int i=0, u, v, w; i<m;i++) {
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0, 0, INT_MAX);
    cin>>q;
    while(q--) {
        int a,b;
        cin>>a>>b;
        lca_algo(a, b);
    }
}
    

int main(void)
{    
    FIO;
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}

/*********************MAIN PROGRAM*************************/