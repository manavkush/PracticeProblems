#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
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
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
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
int n, m;
string a, b;
int vis[5003][5003];
int dp[5003][5003];

int solve(int i, int j) {
    // debug(i, j);
    if (i < 0 || j < 0) {
        return (i + 1 + j + 1);
    } else if (vis[i][j]) {
        return dp[i][j];
    } else if (a[i] == b[j]) {
        // debug("#");
        vis[i][j] = 1;
        return (dp[i][j] = solve(i - 1, j - 1));
    } else {
        // debug("*");
        vis[i][j] = 1;
        int first = 1 + solve(i, j - 1);
        int second = 1 + solve(i - 1, j);
        int third = 1 + solve(i - 1, j - 1);
        dp[i][j] = min(min(first, second), third);
        return dp[i][j];
    }
}

int32_t main() {
    FIO;
    cin >> a >> b;
    n = a.length();
    m = b.length();

    memset(dp, INT_MAX, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    cout << solve(n - 1, m - 1);
}