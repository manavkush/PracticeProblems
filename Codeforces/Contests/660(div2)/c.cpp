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
const int N=1e5+2;
vector<int> adj[N];
bool vis[N];
int ppl[N];
int hpp[N];
lli popbelow[N];
lli hppbelow[N];

class ret
{
    public:
        lli sum;
        lli hpp;
};

ret dfscheck(int s)
{
    vis[s]=1;
    ret ans;
    // ans.sum=ppl[s];
    // ans.hpp=hpp[s];
    ans.sum=0;
    ans.hpp=0;
    for(auto x: adj[s])
    {
        ret temp;
        if(vis[x])
            continue;
        vis[x]=1;
        temp=dfscheck(x);
        ans.hpp+=temp.hpp;
        ans.sum+=temp.sum;
    }
    popbelow[s]=ans.sum;
    hppbelow[s]=ans.hpp;
    return ans;
}
bool fin=false;

int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        re1(i,1,n+1)
            cin>>ppl[i];
        re1(i,1,n+1)
            cin>>hpp[i];
        re(i,n-1)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int flag=0;
        re1(i,1,n+1)
            if(hpp[i]>m||hpp[i]<-1*m)
            {
                flag=1;
                cout<<"NO\n";
                break;
            }

        dfscheck(1);
        for(int i=1;i<=n;i++)
        {
            if(popbelow[i]<hpp[i])
            {
                flag=1;
                cout<<"NO\n";
                break;
            }
            else if(popbelow[i]<-1*hpp[i])
            {
                flag=1;
                cout<<"NO\n";
                break;
            }
        }

        if(flag)    continue;
        


    }
}