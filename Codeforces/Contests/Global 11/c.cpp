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
const int N=1e5+2;
vi a(N);
vi x(N);
vi y(N);
int r,n;
int dp[N];

// int solve(int t,int x1,int y1,int i)
// {
//     // debug(x1,y1,t,i,dp[i]);
//     if(i>=n)
//         return 0;
//     // if(dp[i]!=-1)
//     // {
//     //     return dp[i];
//     // }
//     if(a[i]-t <abs(x[i]-x1)+abs(y[i]-y1))
//     {
//         if(dp[i]!=-1)
//         {
//             return dp[i];
//         }
//         return dp[i] = solve(t,x1,y1,i+1);
//     }
//     else 
//     {
//         // cout<<"* ";
//         return dp[i] = max(solve(t,x1,y1,i+1),solve(a[i],x[i],y[i],i+1)+1);
//     }
// }
int dp[N];

int solve(int i,int j) {
    if(j>n)
        return 0;
    
    if(a[j]-a[i] < abs(x[i]-x[j])+abs(y[i]-y[j]))
    {
        return solve(i,j+1);
    }
    else
    {
        return max(solve(i,j+1),1+solve(j,j+1));
    }
}

int32_t main()
{
    FIO;
    cin>>r>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>x[i];
        cin>>y[i];
    }
    a[0]=0;
    x[0]=1;
    y[0]=1;
    
    int ans= solve(0,1);
    cout<<ans;
}