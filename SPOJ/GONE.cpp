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
map<int,int> primes;
int dp[10][82][2]; // digits, sum, tight

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

int rec(int num, int dig, int n, bool tight) {
    if(num<=1) {
        return 0;
    }
    if(dig == 0) {
        if(primes.find(n)==primes.end()) {
            return 0;
        } else {
            debug(num, dig, n, tight);
            return 1;
        }
    }
    if(dp[dig][n][tight]!=-1) {
        return dp[dig][n][tight];
    }
    int ans = 0;
    int low = pow(10, dig-1);
    int ub = tight ? (num / low) % 10 : 9;
    for(int i=0;i<=ub;i++) {
        ans += rec(num, dig-1, n+i, tight&&(ub==i));
    }
    return (dp[dig][n][tight] = ans);
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    for (int i = 2; i <= 72; i++) {
        if (isPrime(i))
            primes[i]++;
    }
    
    while(t--) {
        int l,r;
        cin>>l>>r;
        memset(dp, -1, sizeof(dp));
        int len2 = floor(log10(r) + 1);
        int ans2 = rec(r, len2, 0, 1);
        debug(len2, ans2);
        int ans1;
        memset(dp, -1, sizeof(dp));
        if(l<=1) {
            ans1 = 0;
        } else {
            int len1 = (l<=1 ? l : floor(log10(l-1) + 1));
            ans1 = rec(l-1, len1, 0, 1);
        }
        cout<<ans2 - ans1<<endl;
    }
}