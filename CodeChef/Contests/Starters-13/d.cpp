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
void solve() {
    int a,b;
    cin>>a>>b;
    unordered_map<int,int> hash1;
    int ans = 1;
    if(a%2==0)  ans = 2;
    while(a%2==0) {
        hash1[2]++;
        a/=2;
    }
    for (int i = 3; i <= sqrt(a); i = i + 2)
    {
        if(a%i==0)  ans*=i;
        while (a % i == 0)
        {
            hash1[i]++;
            // cout << i << " ";
            a = a/i;
        }
    }
    if(a>2) {
        ans*=a;
        hash1[a]++;
    }
    if(b%ans==0)    {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
    return;
    // for(auto x: hash1) {
    //     if(b%x.first!=0)   {
    //         cout<<"NO\n";
    //         return;
    //     }
    // }
    // cout<<"YES\n";
    // return;

    // while(b%2==0) {
    //     hash2[2]++;
    //     b/=2;
    // }
    // for (int i = 3; i <= sqrt(b); i = i + 2)
    // {
    //     while (b % i == 0)
    //     {
    //         hash2[i]++;
    //         // cout << i << " ";
    //         b = b/i;
    //     }
    // }
    // if(b>2) {
    //     hash2[b]++;
    // }

    // bool flag = 0;
    // for(auto x: hash1) {
    //     // debug(x);
    //     if(hash2.find(x.ff)==hash2.end()) {
    //         cout<<"NO\n";
    //         return;
    //     }
    // }
    // cout<<"YES\n";
    // return;
}

int32_t main()
{
    FIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}