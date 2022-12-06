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
    vi a(n+1);
    re(i,n) {
        cin>>a[i+1];
    }
    vector<int> taken(n+1);
    vi b(n+1);
    vi rem;
    vi from;
    int cnt = 0;
    // If the target node is not taken, we assign the mapping
    re1(i,1,n) {
        if(!taken[a[i]]) {
            taken[a[i]] = i;
            b[i] = a[i];
            cnt++;
        }
    }
    // We now converts the paths to cycles
    re1(i,1,n) {
        // if i has no incoming edge but has outgoing edge
        if ((b[i]!=0) and (taken[i]==0)) {
            int curr = i;

            while(b[curr]!=0) {
                curr = b[curr];
            }
            b[curr] = i;
            taken[i] = curr;
        }
    }
    // Till now we have completed the paths to cycles
    re1(i,1,n) {
        if(b[i]==0) {
            rem.push_back(i);
        }
    }
    if(rem.size()==1) {
        int x = rem[0];
        int tar = a[x];
        int prev = taken[tar];
        b[x] = tar;
        b[prev] = x;
    } else if(rem.size()>1) {
        int sz = rem.size();
        for(int i=0;i<rem.size();i++) {
            b[rem[i]] = rem[(i+1)%sz];
        }
    }

    cout<<cnt<<endl;
    re1(i,1,n) {
        cout<<b[i]<<" ";
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
