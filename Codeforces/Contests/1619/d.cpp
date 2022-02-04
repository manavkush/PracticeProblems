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
int m, n;
bool check(int minjoy, vector<vector<int>>& mat)
{
    // debug(minjoy);
    int vis_shop = 0;
    vector<int> friendshop(n, -1);
    unordered_map<int, int> shoptofriend; // stores the shops
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (mat[j][i] >= minjoy) {
                friendshop[i] = j;
                shoptofriend[j]++;
            }
        }
    }
    // If no shop has a gift for the friend >= minjoy
    for (int i = 0; i < n; i++) {
        if (friendshop[i] == -1)
            return false;
    }
    for (auto x : shoptofriend) {
        if (x.second > 1)
            return true;
    }
    return false;
}
void solve()
{
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    re(i, m)
    {
        re(j, n)
        {
            cin >> mat[i][j];
        }
    }
    // check if minimum joy of all friends in n-1 shops is >= mid
    int l = 1;
    int r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid, mat)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}
int32_t main()
{
    FIO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}