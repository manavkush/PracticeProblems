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
void solve()
{
    int n;
    cin >> n;
    map<string, int> score;
    vector<pair<string, int>> inp;
    for (int i = 0; i < n; i++)
    {
        string name;
        int points;
        cin >> name >> points;
        inp.pb({name, points});
        // inp[name].pb(points);
        score[name] += points;
    }
    int max_score = INT_MIN, max_count = 1;
    vector<string> max_people;
    tr(it, score)
    {
        if (it->second == max_score)
        {
            max_count++;
            max_people.pb(it->first);
        }
        else if (it->second > max_score)
        {
            max_score = it->second;
            max_count = 1;
            max_people.clear();
            max_people.pb(it->first);
        }
    }
    // tr(it, inp)
    // {
    //     debug(it->ff, it->ss);
    // }
    if (max_count == 1)
    {
        cout << max_people[0];
        return;
    }
    else
    {
        string ans;
        map<string, int> result;
        re(i, inp.size())
        {
            result[inp[i].ff] += inp[i].ss;
            if (result[inp[i].ff] >= max_score and score[inp[i].ff] == max_score)
            {
                cout << inp[i].ff;
                return;
            }
        }
    }
}
int32_t main()
{
    FIO;
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}