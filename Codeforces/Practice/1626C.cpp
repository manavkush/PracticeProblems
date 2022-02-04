// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
<<<<<<< HEAD
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
=======
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
>>>>>>> 16d7c3a381667495b6c63dc1deb27a9b85b6879d
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
<<<<<<< HEAD
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
=======
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
>>>>>>> 16d7c3a381667495b6c63dc1deb27a9b85b6879d
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
<<<<<<< HEAD
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
=======
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x)
>>>>>>> 16d7c3a381667495b6c63dc1deb27a9b85b6879d
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
<<<<<<< HEAD
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
=======
void __print(const T& x)
{
    int f = 0;
    cerr << '{';
    for (auto& i : x)
>>>>>>> 16d7c3a381667495b6c63dc1deb27a9b85b6879d
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
<<<<<<< HEAD
void solve() {
    int n;
    cin>>n;
    vi seconds(n), health(n);
    re(i,n) {
        cin>>seconds[i];
    }
    re(i,n) {
        cin>>health[i];
    }
    int ans = 0;
    int fin = n-1;
    int finh = n;
    for(int i=n-2;i>=0;i--) {
        if(seconds[fin]-seconds[i]>=health[fin]) {
            int diff = seconds[fin]-seconds[i];
            ans += (diff*(diff+1))/2;
            fin = i;
        }
    }
    if(fin==1)
    ans += (health[fin]*(health[fin]+1))/2;
    else
    ans += (seconds[fin]*(seconds[fin]+1))/2;

    cout<<ans<<endl;
=======
void solve()
{
    int n;
    cin >> n;
    vi k(n), h(n);
    re(i, n)
    {
        cin >> k[i];
    }
    re(i, n)
    {
        cin >> h[i];
    }
    int ans = 0;
    int curr = 0;
    re(i, n)
    {
        }
>>>>>>> 16d7c3a381667495b6c63dc1deb27a9b85b6879d
}
int32_t main()
{
    FIO;
<<<<<<< HEAD
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();    
=======
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
>>>>>>> 16d7c3a381667495b6c63dc1deb27a9b85b6879d
    }
}
