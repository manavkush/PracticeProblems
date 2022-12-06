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

int comp(string &s1, string &s2) {
    int i = s1.length()-1, j = s2.length()-1;
    
    while(i>=0 and j>=0) {
        if(s1[i]<s2[j])
            return 1;
        else if(s1[i]>s2[j]) {
            return -1;
        } else {
            i--, j--;
        }
    }
    return 0;
    // if(i<0 and j<0)
    //     return 0;
    // else if(i<0)
    //     return 1;
    // else
    //     return -1;
}

int util(vector<vector<int>> &dp, string &s, int i, int f) {
    if(i>=f) {
        return 0;
    }
    if(dp[i][f]!=-2) {
        return dp[i][f];
    }
    // front
    int a1 = util(dp, s, i+2, f);
    int a2 = util(dp, s, i+1, f-1);
    int a3 = util(dp, s, i, f-2);
    int ans = 0;
    int leftpick, rightpick;
    {
        // left pick
        leftpick = 1;
        if(a1==0 and s[i]==s[i+1])
            leftpick = 0;
        if(a2==0 and s[i]==s[f])
            leftpick = 0;
    }
    {
        // rightpick
        rightpick = 1;
        if(a3==0 and s[f]==s[f-1])
            rightpick = 0;
        if(a3==0 and s[i]==s[f])
            rightpick = 0;
    }
    return dp[i][f] = min(leftpick, rightpick);

    // int ans1 = util(dp, s, 0, i+1, f, alice, bob);
    // int ans2 = util(dp, s, 0, i, f-1, alice, bob);

    // if(turn) {
    //     int ans1 = util(dp, s, 0, i+1, f, alice, bob);
    //     int ans2 = util(dp, s, 0, i, f-1, alice, bob);
    //     bob += s[i];
    //     bob.pop_back();

    //     bob += s[f];
    //     bob.pop_back();
    //     debug(i,f,"Bob", ans1,ans2);
        
    //     return dp[i][f] = min(ans1, ans2);
    // } else {
    //     alice += s[i];
    //     int ans1 = util(dp, s, 1, i+1, f, alice, bob);
    //     alice.pop_back();
        
    //     alice += s[f];
    //     int ans2 = util(dp, s, 1, i, f-1, alice, bob);
    //     alice.pop_back();

    //     debug(i,f,"Alice", ans1, ans2);
    //     return dp[i][f] = max(ans1, ans2);
    // }
}

void solve() {
    string s;
    cin>>s;

    vector<vector<int>> dp(1005, vector<int> (1005, -2));
    string alice, bob;
    
    // debug("*");
    int ans = util(dp, s, 0, s.length()-1);
    if(ans == -1) {
        cout<<"Bob\n";
    } else if(ans == 0) {
        cout<<"Draw\n";
    } else {
        cout<<"Alice\n";
    }
}

int main(void)
{    
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}

/*********************MAIN PROGRAM*************************/