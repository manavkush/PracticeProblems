#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int lli;
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
#define re1(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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
vi x,y,z;
lli dp[201][201][201];
bool vis[201][201][201];
lli solve(int i,int j,int k)
{
    if(i<0||j<0||k<0)
        return 0;
    if(vis[i][j][k])
        return dp[i][j][k];
    vis[i][j][k]=1;
    if((i==0&&j==0)||(i==0&&k==0)||(j==0&&k==0))
        return 0;

    return dp[i][j][k]=max(max(solve(i-1,j-1,k)+x[i]*y[j],solve(i-1,j,k-1)+x[i]*z[k]),solve(i,j-1,k-1)+y[j]*z[k]);
}

int main()
{
    FIO;
    int r,g,b;
    cin>>r>>g>>b;
            int temp;
    re(i,r)
    {
        cin>>temp;
        x.pb(temp);
    }
    re(i,g)
    {
        cin>>temp;
        y.pb(temp);
    }
    re(i,b)
    {
        cin>>temp;
        z.pb(temp);
    }
    x.pb(0),y.pb(0),z.pb(0);
    sort(all(x));
    sort(all(y));
    sort(all(z));
    int a=x[0];
    int d=y[0];
    int c=z[0];
    // vis[1][0][0]=1;
    // vis[0][1][0]=1;
    // vis[0][0][1]=1;
    
    // dp[0][1][1]=y[1]*z[1];
    // dp[1][0][1]=x[1]*z[1];
    // dp[1][1][0]=x[1]*y[1];

    //cout<<dp[0][0][0]<<endl;
    cout<<solve(r,g,b);

}