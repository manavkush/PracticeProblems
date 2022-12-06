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
vector<pair<pii,pii>> segs;
struct node {
    int x1,y1,x2,y2;
};
void insseg(int x1, int y1, int x2, int y2) {
    if(x1==x2 and y2==y1) {
        //same point
    } else if(x1==x2 || y1==y2) {
        segs.pb({{x1, y1}, {x2, y2}});
    } else {
        segs.pb({{x1, y1}, {x1, y2}});
        segs.pb({{x1, y2}, {x2, y2}});
    }
}
void solve() {
    vector<int> x(3), y(3);
    re(i,3) {
        cin>>x[i]>>y[i];
    }
    vector<vi> ways = {{0,1,2}, {0,2,1}, {1, 2, 0}};
    int low = INT_MAX;
    vector<node> ans;
    re(i,3) {
        // We'll first join ways[i][0], ways[i][1]
        int x1 = x[ways[i][0]];
        int x2 = x[ways[i][1]];
        int x3 = x[ways[i][2]];
        int y1 = y[ways[i][0]];
        int y2 = y[ways[i][1]];
        int y3 = y[ways[i][2]];

        int curr = abs(x1 - x2) + abs(y1 - y2);
        if(x3>=min(x1,x2) and x3<=min(x1,x2)) {
            
        } else if(y3>=min(y1,y2) and y3<=min(y1,y2)) {

        } else {

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
