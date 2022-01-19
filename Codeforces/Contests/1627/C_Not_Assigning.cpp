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
const int N = 1e5 + 5;
vector<vector<int>> adj;
map<pii, int> weights;
void bfs(int s, vector<bool>& vis)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    int sz = q.size();
    int dis = 0;
    while (!q.empty()) {
        int top = q.front();
        // debug(top);
        q.pop();
        sz--;

        for (auto x : adj[top]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push(x);
                if (dis & 1) {
                    weights[{ x, top }] = 2;
                    weights[{ top, x }] = 2;
                } else {
                    weights[{ x, top }] = 3;
                    weights[{ top, x }] = 3;
                }
            }
        }
        if (sz == 0) {
            sz = q.size();
            dis++;
        }
    }
    // debug("");
}

void solve()
{
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    vector<pii> vec;
    re(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vec.pb({ a, b });
    }
    int start = 1;
    // remove those with more than 2 neighbours
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 2) {
            cout << -1 << endl;
            return;
        } else if (adj[i].size() == 1) {
            start = i;
        }
    }

    vector<bool> vis(n + 1, 0);
    bfs(start, vis);
    for (auto x : vec) {
        cout << weights[x] << " ";
    }
    cout << endl;
    adj.clear();
    weights.clear();
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
