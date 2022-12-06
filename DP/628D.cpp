// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

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
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }
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
int dp[N][N][2];

int rec(string a, int n, int m, int d) {
    // initializing the dp grid to 0
    re(i,n+1) re(j,m) re(k,2) dp[i][j][k] = 0;
    dp[0][0][1] = 1;    // 0 length with 0 remainder -> true for tight condition

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<2;k++) {
                int ub = (k==1 ? a[i]-'0' : 9);
                for(int p = 0; p <= ub; p++) {
                    if((i&1) and (p!=d)) continue;
                    if(!(i&1) and (p==d)) continue;
                    int i2 = i+1;
                    int j2 = (10*j + p)%m;
                    int k2 = (k and (p==ub));
                    inc(dp[i2][j2][k2], dp[i][j][k]);
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<2;i++) {
        inc(ans, dp[n][0][i]);
    }
    return ans;
}

int good(string a, int n, int m , int d) {
    int rem = 0;    // store the remainder
    for(int i=0;i<n;i++) {
        int p = a[i] - '0';
        if((i&1) and (p!=d)) return 0;
        if(!(i&1) and (p==d)) return 0;
        rem = (rem*10 + p)%m;
    }
    return !rem;
}

void solve() {
    int m,d;
    cin>>m>>d;
    string a,b;
    cin>>a>>b ;
    int n = a.length();
    int ans = rec(b, n, m, d);
    dec(ans, rec(a, n, m, d));
    inc(ans, good(a, n, m, d));
    cout<<ans<<endl;
}
int32_t main()
{
    FIO;
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();    
    }
}
