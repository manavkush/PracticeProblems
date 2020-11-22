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
int n,m;
int grid[26][26];
int pref[26][26];

void makeprefix()
{
    for(int i=1;i<=n;i++)
    {
        pref[i][1]=pref[i-1][1]+grid[i][1];
    }
    for(int i=1;i<=m;i++)
    {
        pref[1][i] = pref[1][i-1]+grid[1][i];
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+grid[i][j];
        }
    }
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    memset(grid,0,sizeof(grid));
    memset(pref,0,sizeof(pref));
    re(i,n)
    {
        re(j,m)
        {
            char ch;
            cin>>ch;
            grid[i+1][j+1] = ch -'0';
        }
    }
    makeprefix();
    // re1(i,1,n)
    // {
    //     re1(j,1,m)
    //     {
    //         cout<<pref[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans=0;
    for(int x1=1;x1<=n;x1++)
    {
        for(int y1=1;y1<=m;y1++)
        {

            for(int x2=x1;x2<=n;x2++)
            {
                for(int y2=y1;y2<=m;y2++)
                {
                    int prf = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
                    if(prf==0)
                    {
                        ans = max(ans,2*(y2-y1+x2-x1+2));
                    }
                }
            }
        }
    }
    cout<<ans;
}