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
int p,f;
int s,w;
int cs,cw;
void solve()
{
    int n,m,scount,acount,sweight,aweight;
    cin>>n>>m>>scount>>acount>>sweight>>aweight;
    if(sweight>aweight)         // Makes the sword favourable ie lighter
    {
        swap(sweight,aweight);
        swap(acount,scount);
    }
    int sum=n/sweight+m/sweight;        // Both of them have the swords till max capacity
    if(sum<=scount)                     // If the no of swords taken is less than total swords present in the shop
    {
        cout<<" "<<sum<<endl;
        return;
    }
    // We have taken all the swords 
    // We need to distribute the swords in such manner so that we can take the most no of axes along
    int ans=scount;
    for(int i=0;i<=scount;i++)
    {
        int n1=n-i*sweight;                 // Weight remaining on 1st man
        int m1=m-(scount-i)*sweight;        // Weight remaining on 2nd man
        if(m1>=0 &&n1>=0)     // These are the remaining capacities both the men
        {
            ans=max(ans,scount+min(n1/aweight+m1/aweight,acount));
        }
    }
    cout<<ans<<endl;
    return;
}

int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
}