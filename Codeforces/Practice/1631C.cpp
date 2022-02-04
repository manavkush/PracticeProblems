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
int complement(int x, int bits) {
    int ret = 0;
    for(int i=0;i<bits;i++) {
        if( x & (1<<i) ) {
            continue;
        } else {
            ret |= (1<<i);
        }
    }
    return ret;
}
void solve() {
    int n,k;
    cin>>n>>k;
    int n2 = n-1;
    int bits = 0;
    // getting total bits
    while(n2) {
        n2>>=1;
        bits++;
    }
    map<int,int> vis;
    if(k==0) {

    } else if(k==n-1) {
        if(n==4) {
            cout<<-1<<endl;
            return;
        }
        else {
            vis[n-1] = 1;
            vis[n-2] = 1;
            vis[n-3] = 1;
            vis[0] = 1;
            vis[1] = 1;
            vis[2] = 1;
            cout<<0<<" "<<2<<endl;
            cout<<n-3<<" "<<1<<endl;
            cout<<n-1<<" "<<n-2<<endl;
        }
    } else {
        vis[n-1] = 1;
        vis[k] = 1;
        vis[0] = 1;
        vis[complement(k, bits)] = 1;
        cout<<n-1<<" "<<k<<endl;
        cout<<complement(k,bits)<<" "<<0<<endl;
    }
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            int comp = complement(i, bits);
            cout<<i<<" "<<comp<<endl;
            vis[i] = 1;
            vis[comp] = 1;
        }
    }
    // cout<<endl;
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
