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
void solve() {
    string s;
    cin>>s;
    int l=0,r=0;
    int n = s.length();
    int lastodd0 = -1, lasteven0 = -1;
    int lastodd1 = -1, lasteven1 = -1;
    
    int ans = 0;

    for(int r=0;r<n;r++) {
        if(s[r]=='0') {
            if(r&1) {
                ans += min(r-lasteven0, r-lastodd1 );
                lastodd0 = r;
            } else {
                ans += min(r-lastodd0, r-lasteven1);
                lasteven0 = r;
            }
        } else if(s[r]=='1') {
            if(r&1) {
                ans += min(r-lasteven1, r-lastodd0);
                lastodd1 = r;
            } else {
                ans += min(r-lastodd1, r-lasteven0);
                lasteven1 = r;
            }
        } else {
            int ans1=0, ans2=0;
            // if rth pos is assigned 0
            if(r&1) {
                ans1 = min(r-lasteven0, r-lastodd1 );
            } else {
                ans1 = min(r-lastodd0, r-lasteven1);
            }

            if(r&1) {
                ans2 = min(r-lasteven1, r-lastodd0);
            } else {
                ans2 = min(r-lastodd1, r-lasteven0);
            }

            ans += max(ans1, ans2);
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    FIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();    
    }
}
