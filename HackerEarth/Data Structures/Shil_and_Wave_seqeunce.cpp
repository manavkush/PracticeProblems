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
const int N = 1e5+5;
const int mod = 1e9+7;
vector<int> BIT[3];
// 3 BITS are needed. 2nd, 3rd store the increasing and decreasing sequences.
// 1st stores the single elements(which are not sequences)

int query(int bit, int idx) {
    int sum = 0;
    for( ; idx>0 ; idx -= idx&-idx) {
        sum += BIT[bit][idx];
        sum %= mod;
    }
    return sum;
}

void update(int bit, int idx, int diff) {
    for( ; idx<N; idx += idx&-idx) {
        BIT[bit][idx] += diff;
        BIT[bit][idx] %= mod;
    }
}

void init() {
    for(int i=0;i<3;i++) {
        BIT[i].assign(N, 0);
    }
}
void solve() {
    init();
    int n;
    cin>>n;
    vi a(n);
    long long ans = 0;
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    // BIT[0] -> stores the single series
    // BIT[1] -> stores the series with last > sec.last
    // BIT[2] -> stores the series with last < sec.last

    for(int i=0;i<n;i++) {
        int new_inc = query(0, a[i]-1);
        int new_dec = (query(0, N-1) - query(0, a[i]) + mod)%mod;

        int curr_dec = (query(1, N-1) - query(1, a[i]) + mod)%mod;
        int curr_inc = query(2, a[i]-1);

        int incr = (new_inc + curr_inc) % mod;
        int decr = (new_dec + curr_dec) % mod;
        // debug(a[i], find1, find0);
        ans = (ans + (incr + decr)%mod)%mod;
        update(1, a[i], incr);  // increase the count where last el > sec. last el
        update(2, a[i], decr);  // increase the count where last el < sec. last el
        update(0, a[i], 1);     // increase the count of element by 1
    }
    cout<<ans<<endl;
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