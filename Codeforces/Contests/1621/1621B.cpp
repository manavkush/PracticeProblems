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
    vector<int> l(n), r(n), c(n);
    map<int, int> start;
    map<int, int> end;
    map<pii, int> hash;
    int cost = 0;
    vector<int> low(n+1, INT_MAX);
    vector<int> high(n+1, 0);

    re(i,n) {
        cin>>l[i]>>r[i]>>c[i];
        
        if(hash.find({l[i], r[i]}) == hash.end()) {
            hash[{l[i], r[i]}] = c[i];
        } else {
            hash[{l[i], r[i]}] = min(hash[{l[i], r[i]}], c[i]);
        }
        
        if(l[i]==low[i]) {
            start[l[i]] = min(start[l[i]], c[i]);
        } else if(l[i]<low[i]) {
            start[l[i]] = c[i];
        }

        if(r[i]==high[i]) {
            end[r[i]] = min(end[r[i]], c[i]);
        } else if(r[i]>high[i]) {
            end[r[i]] = c[i];
        }

        low[i+1] = min(low[i], l[i]);
        high[i+1] = max(high[i], r[i]);

        int cost = INT_MAX;
        // debug(low[i+1], high[i+1]);
        if(hash.find({low[i+1], high[i+1]}) != hash.end()) {
            cost = hash[{low[i+1], high[i+1]}];
        }
        int costl = start[low[i+1]];
        int costr = end[high[i+1]];
        cost = min(cost, costl + costr);
        cout<<cost<<endl;

        // if(l[i]>low[i] and r[i]<high[i]) continue;
        
        // if(l[i]<=low[i]) {
        //     low[i+1] = l[i];
        //     if(start[low[i+1]])
        // }


        // if(start.find(low[i+1]) == start.end()) {
        //     start[low[i+1]] = c[i];
        // } else {
        //     start[low[i+1]] = min(start[low[i+1]], c[i]) 
        // }
        // start[ l[i] ] = pb({c[i], r[i]});
        // end[r[i]].pb({c[i], l[i]});
    }
    

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
