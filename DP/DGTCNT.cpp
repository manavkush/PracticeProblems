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
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int &a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int &a, int b) { a = sub(a, b); }
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
const int N = 2025;
// int dp[20][20][2];
map<pair<int,pair<vector<int>, bool>>, int> dp;
int rec(int dig, int a,  vector<int> &freq, vector<int> &limit, bool tight)
{
    if (dig <= 0)
    {
        for(int i=0;i<10;i++) {
            if(freq[i]==limit[i]) {
                return 0;
            }
        }
        return 1;
    }
    int low = round(pow(10, dig - 1));
    int up = tight ? (a / low) % 10 : 9;
    int ans = 0;
    if(dp.find({dig, {freq, tight}}) != dp.end()) {
        return dp[{dig, {freq, tight}}];
    }
    for (int i = 0; i <= up; i++)
    {
        vector<int> temp(10, 0);
        if((freq == temp) and i==0) {
            ans += rec(dig - 1, a, freq, limit, (tight && (i == up)));
        } else {
            freq[i]++;
            ans += rec(dig - 1, a, freq, limit, (tight && (i == up)));
            freq[i]--;
        }
    }
    dp[{dig, {freq, tight}}] = ans;
    return ans;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    vi limit(10);
    re(i, 10)
    {
        cin >> limit[i];
    }
    int len = floor(log10(r) + 1);
    vector<int> freq(10, 0);
    dp.clear();
    int ans1 = rec(len, r, freq, limit, 1);
    dp.clear();
    int ans2 = rec(len, l - 1, freq, limit, 1);
    cout << ans1-ans2 << endl;
}
int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
