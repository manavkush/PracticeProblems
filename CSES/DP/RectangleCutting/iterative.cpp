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
vector<vi> vis(503,vi (503,0));
vector<vi> dp(503,vi (503,1000));
// int vis[503][503];
// int dp[503][503];

int solve(int a, int b) {
    if(a>b) {
        swap(a,b);
    }

    // debug(a,b);
    if(a==b) {
        return 0;
    }
    else if(vis[a][b] ) {
        return dp[a][b];
    } else {
        // cout<<"*\n";
        vis[a][b] = 1;
        vis[b][a] = 1;
        for(int i=1;i<b;i++) {
            int b1 = solve(b-i,a);
            int b2 = solve(i,a);
            dp[a][b] = min(dp[a][b] , b1 + b2 +1);
            // debug(a,b,dp[a][b],back, b-i);
        }
        for(int i=1;i<a;i++) {
            int a1 = solve(a-i,b);
            int a2 = solve(i,b);
            dp[a][b] = min(dp[a][b],a1+a2+1);
        }
        
        return dp[a][b];
    }
}

int32_t main()
{
    FIO;
    int a,b;
    cin>>a>>b;
    // vector<vi> dp(a+3,vi (b+3,0) );
    // memset(dp,1, sizeof(dp));
    // memset(vis,0, sizeof(vis));
    if(a>b) {
        swap(a,b);
    }
    cout<<solve(a,b)<<endl;
    // re1(i,1,a) {
    //     re1(j,1,b) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
