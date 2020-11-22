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
const int N = 2003;
int dp[N][N];
int vis[N][N];
bool pal[N][N];
string s;

// This is recursive program to check if string(i:j) is a pallindrome or not

// bool ispallindrome(int i,int j)
// {
//     if(j==i)    return 1;

//     if(j==i+1)
//     {
//         return pal[i][j]=(s[i]==s[j]);
//     }
//     if(j<i)     return 0;


//     if(vis[i][j])
//     {
//         return pal[i][j];
//     }
//     vis[i][j]=1;
//     if(s[i]==s[j])
//     {
//         pal[i][j] = ispallindrome(i+1,j-1);
//         ispallindrome(i,j-1);
//         ispallindrome(i+1,j);
//         return pal[i][j];
//     }
//     else
//     {
//         pal[i][j] = 0;
//         ispallindrome(i+1,j);
//         ispallindrome(i,j-1);
//         return pal[i][j];
//     }
    
// }
//========================================================

// int countpallin(int i,int j)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             if()
//         }
//     }
// }

int32_t main()
{
    FIO;
    cin>>s;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    memset(pal,0,sizeof(pal));

    int n = s.size();
    s='*'+s;
    
    // For length = 1
    for(int i=1;i<=n;i++)
    {
        pal[i][i]=1;
        dp[i][i]=1;
    }
    // ispallindrome(0,n-1);

    // For length = 2
    for(int i=1;i<=n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            pal[i][i+1]=1;
            dp[i][i+1]=3;
        }
    }

    // For length greater than 2
    for(int gap=2;gap<n-1;gap++)
    {
        for(int i=1;i<n-gap;i++)
        {
            int fin=i+gap+1;
            if(s[i]==s[fin]&&pal[i+1][fin-1])
            {
                pal[i][fin]=1;
            }

            if(pal[i][fin]) {
                dp[i][fin] = dp[i][fin-1] + dp[i+1][fin] - dp[i+1][fin-1] + 1;
            }
            else {
                dp[i][fin] = dp[i][fin-1] + dp[i+1][fin] - dp[i+1][fin-1] ;
            }
        }
    }
    re1(i,1,n)
    {
        re1(j,1,n)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    re1(i,1,n)
    {
        re1(j,1,n)
        {
            cout<<(pal[i][j]?1:0)<<" ";
        }
        cout<<endl;
    }


}