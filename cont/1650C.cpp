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
bool comp(pii &a, pii &b) {
    if(a.first!=b.first)
        return a.first < b.first;
    else {
        return a.second < b.second;
    }
}
bool comp2(pii &a, pii &b) {
    return a.second < b.second;
}
void solve() {
    int n,m;
    cin>>n>>m;
    map<int,int> hash;
    vector<pair<int,int>> a;
    priority_queue<pair<int,int>> pq;
    re(i,m) {
        int x,w;
        cin>>x>>w;
        hash[x] = i+1;
        a.push_back({w, x});
    }
    sort(all(a), comp);
    int ans = 0;
    vector<pii> ans2;
    for(int i=0;i<n;i++) {
        ans += a[i].first;
        ans += a[2*n-1-i].first;
        ans2.push_back(a[i]);
        ans2.push_back(a[2*n-1-i]);
    }
    cout<<ans<<endl;
    sort(all(ans2), comp2);
    for(int i=0;i<n;i++) {
        cout<<hash[ans2[i].second]<<" ";
        cout<<hash[ans2[2*n-1-i].second]<<endl;
    }
    cout<<endl;
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
