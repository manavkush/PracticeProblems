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
const int N=2e5;
int vis[N][2];
vi a;
int dp[N][2];
int n;

int solve(vector<int>&a,int i,int turn)
{
    if(i>=n)
        return 0;
    if(vis[i][turn])
        return dp[i][turn];

    vis[i][turn]=1;
    
    if(turn)
    {
        if(i==n-1)
            return dp[i][turn]=0;
        
        return (dp[i][turn] = min ( solve(a,i+1,0),solve(a,i+2,0) ) );
    }
    else
    {
        if(i==n-1)
            return dp[i][turn]=a[i];
        return (dp[i][turn] = min (a[i]+solve(a,i+1,1),a[i]+a[i+1]+solve(a,i+2,1)));
    }
}


int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a.resize(n);
        re(i,n)
        {
            re(j,2)
            {
                dp[i][j]=0;
                vis[i][j]=0;
            }
        }

        re(i,n)
        {
            cin>>a[i];
        }
        
        cout<<solve(a,0,0)<<endl;
        // debug(dp);
        // delete vis;
    }
}