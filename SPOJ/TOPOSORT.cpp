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
vector<int> *adj;
vector<int> vis;
vector<int> ans;

int dfs(int x) {
    // cout << "*";
    vis[x] = 1;
    for (auto y : adj[x]) {
        if (!vis[y])
            dfs(y);
    }
    ans.push_back(x);
}

// Cycle detection
bool check_cycle(int v) {
    vis[v] = 2;  // Currently visiting
    for (auto x : adj[v]) {
        if (vis[x] == 0) {
            if (check_cycle(x)) {  // if there is cycle return true
                return true;
            }
        } else if (vis[x] == 2) {
            return true;
        }
    }
    vis[v] = 1;  // visiting complete
    return false;
}

int32_t main() {
    FIO;
    cin >> n >> m;
    vis.resize(n + 1, 0);
    adj = new vector<int>[n + 1];
    re(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(adj[i]), greater<int>());
    }
    // Finding the cycle
    bool flag = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            flag = check_cycle(i);
        }
        if (flag) {
            break;
        }
    }
    if (flag) {
        cout << "Sandro fails.";
        return 0;
    }

    re(i, n) {
        vis[i + 1] = 0;
    }
    for (int i = n; i >= 1; i--) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    while (ans.size() > 0) {
        cout << ans.back() << " ";
        ans.pop_back();
    }
}