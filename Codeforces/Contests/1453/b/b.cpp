// Author: manavkush
// Date: 14/02/2021

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
// vi a;
int n;

int solve(int m1, vi &a) {

    int ans1=0;
    int curr = 0;
    re(i,n) {
        // debug(ans1);
        if(a[i]+curr==m1) {
            continue;
        } else {
            int diff = m1-(a[i]+curr);
            ans1+=abs(diff);
            curr+=diff;
        }
    }
    return ans1;
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n);
        re(i,n) {
            cin>>a[i];
        }
        int ans=0;
        re(i,n) {
            if(i>0) {
                ans+=abs(a[i]-a[i-1]);
            }
        }
        // cout<<ans<<"\n";
        int mx=0;
        re(i,n) {
            if(i==0) {
                mx=max(mx,abs(a[i+1]-a[i]));
            } else if(i==n-1) {
                mx=max(mx,abs(a[i]-a[i-1]));
            } else {
                mx = max(mx, abs(a[i]-a[i-1])+abs(a[i+1]-a[i])-abs(a[i-1]-a[i+1]));
            }
        }
        ans-=mx;
        cout<<ans<<endl;
    }
}
