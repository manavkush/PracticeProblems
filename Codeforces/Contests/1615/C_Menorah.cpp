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
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    int count = 0; // Places diff
    int acount[2] = { 0, 0 };
    int bcount[2] = { 0, 0 };
    for (int i = 0; i < n; i++) {
        acount[a[i] - '0']++;
        bcount[b[i] - '0']++;
        if (a[i] != b[i])
            count++;
    }
    // operations will be like
    // lit     unlit
    // a        b
    // b+1      a-1
    // a        b

    int ans = n + 1; // Case when #lit are same
    if (acount[1] == bcount[1]) {
        ans = min(ans, count);
    }
    // Case when #lit in b == #unlit in a + 1
    // (One of 1 in a will be there which would map to 1 in target)
    //as count of lit is greater than unlit in a

    if (bcount[1] == acount[0] + 1) {
        ans = min(ans, n - count);
    }
    if (ans > n)
        cout << "-1" << endl;
    else
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
