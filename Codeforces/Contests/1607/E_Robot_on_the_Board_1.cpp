#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
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
pii intersect(pii &a, pii &b) {
    pii ret;
    ret.first = max(a.ff, b.ff);
    ret.second = min(a.ss, b.ss);
    return ret;
}
void solve() {
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    pii xrange = {1, m};
    pii yrange = {1, n};
    int x, y;
    x = y = 0;
    pii ans = {1,1};
    for(int i=0;i<str.size();i++) {
        if(str[i]=='L') {
            x--;
        } else if(str[i]=='U') {
            y--;
        } else if(str[i]=='R') {
            x++;
        } else {
            y++;
        }
        pii x1,y1;
        if(x>=0) {
            x1 = {1, m-x};
        } else {
            x1 = {1-x, m};
        }
        if(y>=0) {
            y1 = {1, n-y};
        } else {
            y1 = {1-y, n};
        }

        xrange = intersect(x1, xrange);
        yrange = intersect(y1, yrange);
        if(xrange.first > xrange.second || yrange.first>yrange.second) {
            break;
        } else {
            ans = {xrange.first, yrange.first};
        }
        // debug(xrange, yrange);
    }
    cout<<ans.second<<" "<<ans.first<<endl;
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}