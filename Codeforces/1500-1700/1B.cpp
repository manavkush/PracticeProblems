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
vi pref(6, 0);
void not_RC(int r, int c)
{
    string col = "";
    bool flag = 0;
    for (int i = 5; i >= 1; i--)
    {
        if (c <= pref[i] and c < pref[i - 1])
        {
            continue;
        }
        if (c <= pref[i] and c > pref[i - 1])
        {
            int dig = i;
            c -= pref[i - 1] + 1;

            for (int j = i; j >= 1; j--)
            {
                // debug(c);
                char temp = 'A';

                temp += (c / pow(26, j - 1));
                col += temp;
                c -= (temp - 'A') * pow(26, j - 1);
                // debug(temp);
            }
            // debug(c);
            break;
        }
    }
    cout << col;
    cout << r << endl;
}

void solve()
{
    string str;
    for (int i = 1; i < 6; i++)
    {
        pref[i] = pow(26, i);
    }
    for (int i = 1; i < 6; i++)
    {
        pref[i] = pref[i] + pref[i - 1];
    }
    cin >> str;
    int n = str.length();
    int count = 0;
    int i = 0;
    int first = -1;
    for (i = 0; i < n; i++)
    {
        if (str[i] - 'A' < 0)
        {
            first = i;
            count++;
            break;
        }
    }
    i++;
    for (; i < n; i++)
    {
        if (str[i] - 'A' >= 0)
        {
            count++;
            break;
        }
    }
    if (count == 2) // RC type
    {
        int r, c;
        string s;
        int i = 0;
        for (i = 1; str[i] != 'C'; i++)
        {
            s += str[i];
        }
        r = stoi(s);
        i++;
        s = "";
        for (; i < n; i++)
        {
            s += str[i];
        }
        c = stoi(s);
        not_RC(r, c);
    }
    else // aa type
    {
        int y = stoi(str.substr(first));
        string temp = str.substr(0, first);
        int sz = temp.size();
        int ans = 0;
        for (int i = 0; i < sz; i++)
        {
            int dig = temp[i] - 'A' + 1;
            ans += (dig * pow(26, sz - i - 1));
        }
        cout << "R" << y << "C" << ans << endl;
    }
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