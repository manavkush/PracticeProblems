// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

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
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x)
{
    int f = 0;
    cerr << '{';
    for (auto& i : x)
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
vi cost(1005, INT_MAX);
void solve()
{
    int n, k;
    cin >> n >> k;
    vi b(n), coins(n);

    re(i, n)
    {
        cin >> b[i];
    }
    re(i, n)
    {
        cin >> coins[i];
    }
    k = min((12 * 1000 + 5ll), k);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); // dp[n][k]

    for (int sum = 0; sum <= k; sum++) {
        for (int j = 1; j <= n; j++) {
            int idx = j - 1;
            int num = b[idx];

            if (cost[num] <= sum) {
                dp[j][sum] = max(dp[j - 1][sum], dp[j - 1][sum - cost[num]] + coins[idx]);
            } else {
                dp[j][sum] = dp[j - 1][sum];
            }
        }
    }
    cout << dp[n][k] << endl;
}
int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;

    cost[1] = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + (i / j) <= 1000)
                cost[i + (i / j)] = min(cost[i + (i / j)], cost[i] + 1);
        }
    }
    while (t--) {
        solve();
    }
}
