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
    int n,m;
    cin>>n>>m;
    vector<int> isprime(2*m+1, 1);
    
    int sqt = sqrt(2*m);
    for(int i=2;i<=sqt;i++) {
        if(!isprime[i]) continue;
        else {
            int j = i+i;
            while(j<=2*m) {
                isprime[j] = 0;
                j += i;
            }
        }
    }
    debug(isprime);

    int diff = 0;
    for(int i=n-1;i>=1;i--) {
        if(isprime[i]) {
            break;
        } else {
            diff++;
        }
    }
    int prime = n-1-diff;
    
    vector<pair<int,int>> adj[n+1];
    re(i,prime) {
        if(i==(prime-1)) {
            adj[i+1].pb({n, 1});
        } else {
            adj[i+1].pb({i+2, 1});
        }
    }
    int edge_left = m-prime;
    int i;
    for(i=m;i<=2*m;i++) {
        if(isprime[i]) break;
    }
    cout<<prime<<" "<<i<<endl;
    int weight_left = i-prime;
    
    for(int i=1;i<n and edge_left>0 ;i++) {
        for(int j=i+2;j<=n and edge_left>0;j++) {
            if(edge_left==1) {
                adj[i].push_back({j, weight_left});
            } else {
                adj[i].push_back({j, 1});
                weight_left--;
            }
        } 
    }
    // cout<<prime<<" "<<
    for(int i=1;i<n;i++) {
        for(auto x: adj[i]) {
            cout<<i<<" "<<x.ff<<" "<<x.ss<<endl;
        }
    }

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
