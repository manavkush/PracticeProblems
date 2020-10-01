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
const int N=3e5+3;
vi a(N);
vector<int> m[N];       // Array to store different value's occurances
int n;

int solve(int mid)
{
    for(int i=1;i<=n;i++)
    {
        if(!m[i].size())
            continue;
        
        int dis=m[i][0];
        int sz=m[i].size();

        for(int j=1;j<sz;j++)
        {
            dis=max(dis,m[i][j]-m[i][j-1]);
        }
        dis=max(dis,n-m[i][sz-1]+1);

        if(dis<=mid)
            return i;   
    }
    return 0;
}

int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a.clear();
        for(int i=1;i<=n;i++)
        {
            m[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            m[a[i]].pb(i);
        }
        int l=1,r=n;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(solve(mid))
                r=mid;
            else
                l=mid;
        }
        
        
        int ans=solve(r);
        re(i,r-1)
        {
            cout<<-1<<" ";
        }
        re1(i,r-1,n-1)
        {
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}