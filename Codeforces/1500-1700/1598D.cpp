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
/*
    After analysing the cases there are 4 cases which give error: 
        2 same topics, 2 same diff;
        2 same topics, 3 same diff;
        3 same topics, 2 same diff;
        3 same topics, 3 same diff;
    
    Only case(1) is valid.
    this would give 3 pairs like: (a,d) , (a, c) , (b, c)
    We will iterate over all the pairs (a,c) and sum the number of possible triplets.
    We've gotten the error cases.
*/
void solve() {
    int n;
    cin>>n;
    vector<pii> arr;
    vector<int> top(n+1);
    vector<int> diff(n+1);
    re(i,n) {
        int a, b;
        cin>>a>>b;
        arr.pb({a,b});
        top[a]++;
        diff[b]++;
    }
    int count = n*(n-1)*(n-2)/6;
    int neg = 0;
    for(auto x: arr) {
        count -= (top[x.first]-1)*(diff[x.second]-1);
    }
    cout<<count<<endl;
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}