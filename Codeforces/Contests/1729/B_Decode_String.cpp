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
unordered_map<int, char> ch;

bool util(string &s, int i, int n, string &ans) {
    if(i==n) {
        return true;
    }
    // if(i==n-1) {
    //     if(s[i]=='0')
    //         return false;
    //     ans += ch[s[i]-'0'];
    //     return true;
    // }
    if(i<n-2) {
        if(s[i]=='1' and s[i+2]=='0') {
            int num = 10*(s[i]-'0') + (s[i+1]-'0');
            ans += ch[num];
            if(util(s, i+3, n, ans))
                return true;
            ans.pop_back();
        }
        if(s[i]=='2' and s[i+1]<='6' and s[i+2]=='0') {
            int num = 10*(s[i]-'0') + (s[i+1]-'0');
            ans += ch[num];
            if(util(s, i+3, n, ans))
                return true;
            ans.pop_back();
        }
    }
    if(s[i]=='0') {
        return false;
    }
    ans += ch[s[i]-'0'];
    if(util(s, i+1, n, ans)) {
        return true;
    } 
    ans.pop_back();
    return false;
}

void solve() {
    int n;cin>>n;
    string s;
    cin>>s;
    string ans;
    util(s, 0, n, ans);
    cout<<ans<<endl;
}

int main(void)
{    
    FIO;
    for(int i=0;i<26;i++) {
        ch[i+1] = 'a'+i;
    }
    int tt = 1;
    cin >> tt;
    // debug(ch);
    while (tt--)
    {
        solve();
    }
    return 0;
}

/*********************MAIN PROGRAM*************************/