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
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
//====================================DEBUG TEMPLATE==============================================

int n;
bool vis[1005][1005];
int dp[1005][1005];      // initial final 

char ch;
string str;
int solve(int i,int f,int p)
{
    if(i>f)
    {
        if(p==0)
            return -1000000;
        return 0;
    }
    if(vis[i][f])
        return dp[i][f];
    else
    {
        vis[i][f]=1;
        int tmp=-1000000;
        if(str[i]==str[f])
        {
            tmp = 2 + solve(i+1,f-1,p or str[i]==ch);
            if(i==f)
            tmp--;
        }
        // else
        {
            tmp = max( max(solve(i+1,f,p) , solve(i,f-1,p) ), tmp );
        }
        dp[i][f] = tmp;
        return dp[i][f];
    }
    
    
}

int32_t main()
{
    FIO;
    int t;
	cin>>t;
	while(t--)
	{
        
		cin>>ch;
		cin>>str;
		n=str.length();
		
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        
		int ans = solve(0,n-1,0);
        cout<<((ans<0)?0:ans)<<endl;
        
	}
    // time();

}