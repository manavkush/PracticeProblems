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
int k,n;
const int N=1001;
bool vis[1001][1001];
lli val[1001][1001];

lli sum[1001][1001];
vector<int> a;

void init()
{
    re(i,N)
    re(j,N)
    {
        vis[i][j]=0;
        val[i][j]=0;
        sum[i][j]=0;
    }
    
}

lli solve(int s,int e)
{
    if(vis[s][e])
    {
        return val[s][e];
    }
    vis[s][e]=true;
    if(s==e)
    {
        return val[s][e]=sum[s][e];
    }
    lli ans=LLONG_MAX;
    for(int i=s+1;i<=e;i++)
    {
        ans=min(ans,solve(i,e)+sum[s][i-1]);
    }
    ans=min(ans,sum[s][e]);
    //cout<<s<<" "<<e<<" :"<<ans<<endl;
    return (val[s][e]=ans);
    
    // lli temp=min(solve(a,s+1,e)+k,solve(a,s,e-1)+k);
    // val[s][e]=min(temp,sum[s][e]);

}

int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        a.pb(0);
        re(i,n)
        {
            int temp;
            cin>>temp;
            a.pb(temp);
        }
        init();
        multiset<int> s;
        // Precalculations
        for(int i=1;i<=n;i++)
        {
            s.clear();
            lli curr=k;
            for(int j=i;j<=n;j++)
            {
                if(s.find(a[j])==s.end())
                {
                    s.insert(a[j]);
                    sum[i][j]=curr;
                }
                else
                {
                    if(s.count(a[j])==1)
                    {
                        s.insert(a[j]);
                        curr+=2;
                        sum[i][j]=curr;
                    }
                    else
                    {
                        s.insert(a[j]);
                        curr+=1;
                        sum[i][j]=curr;
                    }
                }
            }
        }
        s.clear();
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=i;j<n+1;j++)
        //     {
        //         cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
        //     }
        // }
        
        cout<<solve(1,n)<<endl;
        a.clear();

    }
}