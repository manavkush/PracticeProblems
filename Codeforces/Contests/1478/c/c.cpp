// Author: manavkush
// Date: 28/01/2021

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
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a;
        set<int> s;
        bool flag = 0;
        bool odd = 0;
        re(i,2*n) {
            int temp;
            cin>>temp;
            if(temp&1) {
                odd = 1;
            }
            s.insert(temp/2);
        }
        if(odd) {
            cout<<"NO\n";
            continue;
        }
        if(s.size()!=n) {
            cout<<"NO\n";
            continue;
        }

        for(auto itr: s) {
            a.push_back(itr);
        }
        reverse(all(a));
        // debug(a);
        vector<int> dp(n);
        for(int i=0;i<n;i++) {
            if(i==0) {
                dp[i] = a[i]/n;
                if(dp[i]<=0 or ((dp[i]*n)!=a[i])) {
                    flag = 1;
                    break;
                }
            } else {
                int res = (a[i]-dp[i-1])/(n-i);
                dp[i] = dp[i-1]+res;
                if(res<=0 || ((res*(n-i)+dp[i-1])!=a[i])) {
                    flag = 1;
                    break;
                }
            }
            // cout<<"*";
            // debug(dp);
        }
        if(flag) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }
}
