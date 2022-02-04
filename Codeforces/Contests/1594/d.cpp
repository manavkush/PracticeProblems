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
/* 
    crux lies in the relationship i.e. the statement
    we make a truth table and infer that for a statement
    x --- z----> y
    is same as
    x ^ z = y
    when imposter = 1, crewmate = 0;

    using property of xor we infer that the y^z = x
    
    IMP
    ## thus making the graph undirected
*/
vector<vector<pii>> adj;
vector<int> vis;
vector<int> col;
bool flag = 0;
vector<int> counts(2, 0);
int n, m;

void dfs(int s, int status)
{
    vis[s] = 1;
    col[s] = status;
    counts[status]++;

    for (auto x : adj[s]) {
        int y = x.first;
        int z = x.second;

        if (vis[y] == -1) {
            dfs(y, status ^ z);
        } else {
            if (col[y] == status ^ z) {
                continue;
            } else {
                flag = 1;
                return;
            }
        }
    }
    // debug(s, counts, flag);
}
void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, {});
    int c = 0;
    int ans = 0;
    flag = 0;
    // input
    re(i, m)
    {
        int u, v;
        string w;
        cin >> u >> v >> w;
        if (w[0] == 'i')
            c = 1;
        else
            c = 0;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }

    // execution
    vis.assign(n + 1, -1);
    col.assign(n + 1, -1);
    // for (int i = 1; i <= n; i++) {
    //     debug(adj[i]);
    // }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            counts.assign(2, 0);
            dfs(i, 1);
            ans += (*max_element(all(counts)));
            // debug(ans);
        }
    }
    // debug(ans, flag);

    if (flag) {
        cout << -1 << endl;
    } else
        cout << ans << endl;
}
int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
