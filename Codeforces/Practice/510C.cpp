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
bool flag = 0;
vector<vector<int>> adj(26);
vector<int> st;
vector<int> vis(26, 0);

void dfs(vector<vector<int>> &adj, int s) {
    vis[s] = 2;
    
    for(auto &x: adj[s]) {
        if(vis[x]==2) {
            flag = 1;
            return;
        } else if(vis[x] == 1) {
            continue;
        } else {
            dfs(adj, x);
        }
    }
    st.push_back(s);
    vis[s] = 1;
}

void solve() {
    int n;
    cin>>n;
    vector<string> vec(n);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }

    for(int row=0; row<n-1; row++) {
        int i;
        for(i=0; i < min(vec[row].length(), vec[row+1].length());i++) {
            if(vec[row][i] != vec[row+1][i]) {
                adj[vec[row][i]-'a'].push_back(vec[row+1][i]-'a');
                break;
            }
        }
        if(vec[row].length() > vec[row+1].length() and i==vec[row+1].length()) {
            flag = 1;
        }
    }

    // debug(adj);

    for(int i=25;i>=0;i--) {
        if(vis[i]==0)
            dfs(adj, i);
        // debug(i, vis);
    }

    if(flag) {
        cout<<"Impossible\n";
    } else {
        reverse(st.begin(), st.end());
        for(auto &x: st) {
            char c = 'a' + x;
            cout<<c;
        }
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