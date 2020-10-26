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
const int mod = 1e9+7;
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
vi fact(5002);
vi vis(5002);

int factorial(int n) 
{
    if(n<0)
        return 0;
    if(n==1||n==0)
        return 1ll;
    if(vis[n])
    {
        return fact[n];
    }
    vis[n]=1;
    (fact[n]=(n*factorial(n-1))%mod); 
    return fact[n];
}

int NCR(int n, int r)
{
    if (r == 0) return 1;
    if (r<0|| n<0||r>n)
        return 0;
    if (r > n / 2) 
        return NCR(n, n - r);

    int res = 1ll; 

    for (int k = 1; k <= r; ++k)
    {
        res = (res *( n - k + 1))%mod;
        res = (res/k)%mod;
    }

    return res%mod;
}
int NPR(int n, int r)
{
    if (r == 0) return 1;
    if (r<0|| n<0||r>n)
        return 0;
    int res=1;
    for(int i=n;i>n-r;i--)
    {
        res*=i;
        res=(res%mod);
    }
    return res;
}

int32_t main()
{
    FIO;
    int n,x,pos;
    cin>>n>>x>>pos;
    factorial(1001);
    
    int l=0;
    int r=n;
    int cntless=0;      // storing the counts of less numbers needed
    int cntmore=0;      // storing the counts of more numbers needed
    fact[0]=fact[1]=1;
    
    while(l<r)
    {
        int mid=(l+r)/2;
        if(mid<pos)    cntless++;
        if(mid>pos)    cntmore++;
        if(mid<=pos)   l=mid+1;
        else {
            r= mid;
        }
    }
    
    int haveless=x-1;
    int havemore=n-x;
    {
        cout<<  NPR(n-x,cntmore) * NPR(x-1,cntless)%mod * fact[n-cntmore-cntless-1]%mod ;
    }
    
}