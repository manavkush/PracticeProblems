#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> pipii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
//const double PI = acos(-1);
const int mod = 1e9 + 7;

// ----------------------DEBUG TEMPLATE--------------------------
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

// ----------------------DEBUG TEMPLATE--------------------------
#define N 3005
vector<pair<int, int>> *adj;
bool vis[N];
void djikstraSSSP(int V, int E, int S) {
    vi dist(V + 1, INT_MAX);
    dist[S] = 0;

    set<pair<int, int>> s;
    s.insert(mp(0, S));

    while (!s.empty()) {
        auto t = *(s.begin());
        s.erase(s.begin());

        int pId = t.ss;
        int pDist = t.ff;

        vis[pId] = true;
        cout << pId << endl;

        for (auto nbr : adj[pId]) {
            int nbrId = nbr.ff;
            int edgeLen = nbr.ss;

            if (pDist + edgeLen < dist[nbrId]) {
                auto temp = s.find(mp(dist[nbrId], nbrId));
                if (temp != s.end()) {
                    s.erase(temp);
                }
                dist[nbrId] = pDist + edgeLen;
                s.insert(mp(dist[nbrId], nbrId));
            }
        }
    }
}
void tc() {
    int V, E;
    cin >> V >> E;
    adj = new vector<pair<int, int>>[V + 1];
    memset(vis, false, sizeof(vis));
    fo(i, E) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back(mp(v, l));
    }
    int s;
    s = 0;
    djikstraSSSP(V, E, s);
    fo(i, V) {
        if (!vis[i]) {
            cout << i << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--) {
        tc();
    }
}