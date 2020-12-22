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

int32_t main()
{
    FIO;
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    re(i,n) {
        cin>>a[i];
    }
    int dp[n+1][m+3];
    memset(dp,0,sizeof(dp));
    
    if(a[0]==0) {
        for(int i=1;i<=m;i++) {
            dp[1][i]=1;
        }
    } else {
        dp[1][a[0]] = 1;
    }
    // dp[n][m]  ---> Stores the no of arrays possible till index 'n' and ending at value 'm';
    // dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
    
    for(int i=2;i<=n;i++) {
        int val = a[i-1];
        if(a[i-1]==0) 
        {
            for(int j=1;j<=m;j++) {
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
            }
        }
        else 
        {
            dp[i][val] = (dp[i-1][val-1] + dp[i-1][val] + dp[i-1][val+1])%mod;
        }
    }

    // For printing the output of the dp array.
    /*
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<=m+1;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    int sum=0;
    if(a[n-1]==0) {
        for(int i=1;i<=m;i++) {
            sum= (sum+dp[n][i])%mod;
        }
        cout<<sum<<endl;
    }
    else {
        cout<<dp[n][a[n-1]]<<endl;   
    }
}
