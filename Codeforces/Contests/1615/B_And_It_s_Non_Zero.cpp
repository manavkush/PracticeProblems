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
    int l,r;
    cin>>l>>r;
    
    int cnt1 = 0, cnt2 = 0;
    int ll = l, rr = r;
    while(ll) {
        cnt1++;
        ll = ll>>1;
    }
    while(rr) {
        cnt2++;
        rr = rr>>1;
    }
    if(cnt1 == cnt2) {
        cout<<0<<endl;
        return;
    } 
    
    int m1 = 0;
    
    re(i,cnt1) {
        m1 = (m1<<1)|1;
    }
    
    int n = r-l+1;

    int even;
    if((r&1) and (l&1)) {
        even = (n/2);
    }else if((r%2==0) and (l%2==0)) {
        even = (n/2)+1;
    } else {
        even = n/2;
    }
    int ans = even;
    int cnt = cnt1;
    // debug(ans);
    for(int i=cnt1; i<=cnt2;i++) {
        if(i==cnt1)
            ans = min(ans,r - m1);
        else if(i==cnt2)
            ans = min(ans, (1<<(cnt2-1)) - l );
        else {
            ans = min(ans, (r-m1) + (1<<(i-1)) - l);
        }
        m1 = (m1<<1)|1;
        // debug(i,ans, m1);
    }
    cout<< ans<<endl;
    return;
    
    // int ans1 = r - m1 + 1 + (1<<cnt) - l;
    // int ans2 = r - m2 + 1 + (1<<(cnt+1)) -l;
    // cout<< min(ans1, ans2) <<endl;
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
