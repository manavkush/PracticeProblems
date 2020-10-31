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
    int h,w;
    cin>>h>>w;
    string grid[h];
    re(i,h)
    {
        cin>>grid[i];
    }
    int q;
    cin>>q;

    int dp[h+1][w+1];

    for(int i=0;i<w+1;i++)
    {
        dp[0][i]=0;
        dp[1][i] = 0;
    }
    for(int i=0;i<h+1;i++)
    {
        dp[i][1]=dp[i][0]=0;
    }

    for(int i=1;i<w;i++)
    {
        if(grid[0][i]=='.'&&grid[0][i-1]=='.')
            dp[1][i+1]=dp[1][i]+1;
        else
            dp[1][i+1]=dp[1][i];
        
    }

    for(int i=1;i<h;i++)
    {
        if(grid[i][0]=='.'&& grid[i-1][0]=='.')
            dp[i+1][1] = dp[i][1]+1;
        else
            dp[i+1][1] =  dp[i][1];
    }
    
    for(int i=1;i<h;i++)
    {
        for(int j=1;j<w;j++)
        {
            if(grid[i][j]=='#')
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j];
            else 
            {
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j];
                if(grid[i][j-1]=='.')
                {
                    dp[i+1][j+1]++;
                }
                if(grid[i-1][j]=='.')
                {
                    dp[i+1][j+1]++;
                }
            }
        }
    }
    // for(int i=0;i<h;i++)
    // {
    //     for(int j=0;j<w;j++)
    //     {
    //         cout<<dp[i+1][j+1]<<" ";
    //     }
    //     cout<<endl;
    // }

    re(i,q)
    {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        
        int ans = dp[r2][c2]-dp[r1-1][c2] - dp[r2][c1-1]    +dp[r1-1][c1-1];
        // cout<<ans<<" ";
        if(c1!=1)
        {
            for(int i=r1;i<=r2;i++)
            {
                if(grid[i-1][c1-1]=='.' && grid[i-1][c1-2]=='.')
                {
                    ans--;
                }
            }
        }
        if(r1!=1)
        {
            for(int i=c1;i<=c2;i++)
            {
                if(grid[r1-1][i-1]=='.' and grid[r1-2][i-1]=='.')
                    ans--;
            }
        }
        
        cout<<ans<<endl;
    }
}