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
string str;           // Secret recipe
int b,s,c;          // No of available ingredients
int cb,cs,cc;       // Cost of each ingredient
int r;              // Money available
int breq,sreq,creq; // Required ingredients for one hamburger

bool solve(int x)
{
    int cost=0;
    if(x*breq>b) {
        cost+=(x*breq-b)*cb;
    }
    
    if(x*creq>c)
    {
        cost+=(x*creq-c)*cc;
    }
    if(x*sreq>s) {
        cost+=(x*sreq-s)*cs;
    }
    return cost<=r;
}

int32_t main()
{
    FIO;
    cin>>str>>b>>s>>c>>cb>>cs>>cc>>r;     // Input
    
    breq=creq=sreq=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='B')
            breq++;
        else if(str[i]=='C')
            creq++;
        else sreq++;
    }

    int l=0;     // Always true
    int r=1e13; // Always false
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(solve(mid))  {
            l=mid;
        }
        else {
            r=mid;
        }
    }
    cout<<l<<endl;
}