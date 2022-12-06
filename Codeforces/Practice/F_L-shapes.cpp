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
vector<int> dr = {-1, 1, 0, 0, 1, -1, -1, 1};
vector<int> dc = {0, 0, -1, 1, 1, -1, 1, -1};
int n,m;

int dfs(vector<vector<char>> &grid, int x, int y) {
    int ans = 0;
    grid[x][y] = '#';
    // debug("*");
    for(int i=0;i<8;i++) {
        int xx = x + dr[i];
        int yy = y + dc[i];
        // debug("*", xx, yy);
        if(xx<0 || yy<0 || xx>=n || yy>=m)
            continue;
        if(grid[xx][yy]=='*') {
            ans += 1 + dfs(grid, xx, yy);
        }
    }
    // debug("#");
    return ans;
}

void solve() {
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char> (m, '.'));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    // vector<int> dx = {1, -1, 0, 0};
    // vector<int> dy = {0, 0, 1, -1};
    // debug("*");
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='*') {
                vector<pair<int,int>> cnt;
                for(int idx = 0; idx<4; idx++) {
                    int x = i+dr[idx];
                    int y = j+dc[idx];
                    if(x<0 || y<0 || x>=n || y>=m)
                        continue;
                    if(grid[x][y]=='*') {
                        cnt.push_back({x, y});
                    }
                }
                if((cnt.size()==2) and 
                 (abs(cnt[0].first - cnt[1].first)==1) and 
                 (abs(cnt[0].second-cnt[1].second)==1)) {
                    // debug("*");
                    if(dfs(grid, i, j)!=2) {
                        cout<<"NO\n";
                        // debug("*1");
                        return;
                    } else {
                        // debug("*2");
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='*') {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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