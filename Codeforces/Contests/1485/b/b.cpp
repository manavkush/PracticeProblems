// Author: manavkush
// Date: 12/02/2021

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


int32_t main()
{
    FIO;
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n,q,k;
        cin>>n>>q>>k;
        vi a(n+1);
        re1(i,1,n) {
            cin>>a[i];
        }
        vi store(n+1);
        vi pref(n+1);
        re1(i,1,n) {
            if(i==0) {
                store[i] = a[i]-1;
                store[i] += a[i+1]-1-a[i];
            } else if(i==n) {
                store[i] += k-a[i];
                store[i] +=a[i]-a[i-1]-1;
            } 
            else {
                store[i] += a[i+1]-1-a[i];
                store[i] += a[i]-1-a[i-1];
            }
        }
        re1(i,1,n) {
            pref[i]=pref[i-1]+store[i];
        }
        debug(store);
        debug(pref);
        while(q--) {
            int l,r;
            cin>>l>>r;
            int ans=0;

            if(r>l) {
                ans+=pref[r-1]-pref[l];
                debug("@",ans);
            }
            ans+=a[l]-1;
            ans+=k-a[r];
            if(l!=r) {
                ans+=a[l+1]-a[l]-1;
                ans+=a[r]-a[r-1]-1;
            } 

            // ans+=store[l]-1;
            // ans+=k-store[r];
            // if(l!=n and (l!=r)) {
            //     ans+=a[l+1]-a[l]-1;
            // } 
            // if(r!=1 and (l!=r) ) {
            //     ans+=a[r]-a[r-1]-1;
            // }
            cout<<ans<<endl;
        }
    }
}
