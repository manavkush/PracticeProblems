// Author: manavkush
// Date: 28/12/2020

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
vi r,b;
int n,m;
int dp[101][101];
bool vis[101][101];

int solve(int i,int j) {
    if(i>=n && j>=m) 
        return 0;
    else if(vis[i][j]) {
        return dp[i][j];
    }
    else {
        vis[i][j]=1;
        if(i>=n) {
            dp[i][j] = max(solve(i,j+1)+b[j],0ll);
        }
        else if(j>=m) {
            dp[i][j] = max(solve(i+1,j)+r[i],0ll);
        }
        else {
            dp[i][j] = max(0ll,max(solve(i,j+1)+b[j],solve(i+1,j)+r[i]));
        }

    }
    return dp[i][j];
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        r.resize(n);
        re(i,n) {
            cin>>r[i];
        }
        cin>>m;
        b.resize(m);
        re(i,m) {
            cin>>b[i];
        }
        re1(i,0,100) {
            re1(j,0,100) {
                dp[i][j]=0;
                vis[i][j]=0;
            }
        }
        cout<<solve(0,0)<<endl;
    }
}
