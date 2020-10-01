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
vector<int> v;
vector<int> req(26, 0);
string a, b;
int t, p;
bool solve(int m)
{
    vector<int> avbl(26, 0);
    for (int i = m; i < t; i++)
    {
        avbl[a[v[i] - 1] - 'a']++;
    }
    bool flag = 1;
    for (int i = 0; i < 26; i++)
    {
        if (avbl[i] < req[i])
        {
            flag = 0;
            break;
        }
    }
    // deb(m);
    debug(avbl);

    return flag;
}

int32_t main()
{
    FIO;

    cin >> a >> b;
    t = a.size();
    p = b.size();
    re(i, p)
    {
        req[b[i] - 'a']++;
    }
    // debug(req);
    v.resize(t);
    re(i, t)
    {
        cin >> v[i];
    }
    int l = 1;     // String can be formed with greater than equal to l
    int r = t + 1; // String cannot be formed form using v{r....t};
    cout << l << " " << r << endl;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (solve(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
        cout << l << " " << r << endl;
    }
    cout << l - 1;
}