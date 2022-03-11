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
    int n;
    cin>>n;
    vi a(n), b(n);
    vector<pii> alist1,blist1, alist2, blist2;
    re(i,n) {
        cin>>a[i];
    }
    re(i,n) {
        cin>>b[i];
    }
    for(int i=0;i<n;i++) {
        alist1.push_back({abs(a[i]-b[0]), i});
        alist2.push_back({abs(a[i]-b[n-1]), i});
        blist1.push_back({abs(b[i]-a[0]), i});
        blist2.push_back({abs(b[i]-a[n-1]), i});
    }
    sort(all(alist1));
    sort(all(alist2));
    sort(all(blist1));
    sort(all(blist2));
    map<int,int> done;
    int sum = 0;
    sum += blist1[0].ff;
    done[blist1[0].ss]++;
    
    if()
    // sum += min(abs(a[0] - blist[0].ff) + abs(a[n-1] - blist[1].ff), abs(a[0] - blist[1].ff) + abs(a[n-1] - blist[1].ff) );
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
