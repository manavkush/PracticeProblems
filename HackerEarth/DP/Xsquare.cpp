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


int main()
{
    FIO;
    int n,q;
    cin>>n>>q;
    int a[n+2];
    int b[n+2];
    re1(i,1,n+1)
    {
        cin>>a[i];
    }
    re1(i,1,n+1)
    {
        cin>>b[i];
    }
    lli sum1[n+2];
    lli sum2[n+2];
    sum1[0]=sum2[0]=0;
    re1(i,1,n+1)
    {
        if(i&1)
        {
            sum1[i]=sum1[i-1]+a[i];
            sum2[i]=sum2[i-1]+b[i];
        }
        else
        {
            sum1[i]=sum1[i-1]+b[i];
            sum2[i]=sum2[i-1]+a[i];
        }
    }
    re(i,q)
    {
        int tp,l,r;
        cin>>tp>>l>>r;
        if(tp==1)
        {
            if(l&1)
            {
                cout<<sum1[r]-sum1[l-1]<<endl;
            }
            else
            {
                cout<<sum2[r]-sum2[l-1]<<endl;
            }
        }
        else
        {
            if(l&1)
            {
                cout<<sum2[r]-sum2[l-1]<<endl;
            }
            else
            {
                cout<<sum1[r]-sum1[l-1]<<endl;
            }
        }
        

    }

}