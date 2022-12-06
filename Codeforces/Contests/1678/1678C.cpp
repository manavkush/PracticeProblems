// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

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
    int n;
    cin>>n;
    vi a(n);
    re(i,n) {
        cin>>a[i];
    }
    vector<vector<int>> vec(n);
    vector<vector<int>> suff(n);
    vector<vector<int>> pref(n);
    vector<int> hash(n+1);
    vector<int> sum(n+1);

    for(int i=n-1;i>=0;i--) {
        hash[a[i]]++;
        sum = hash;
        for(int j=n-1;j>=i;j--) {
            sum[j] += sum[j+1];
        }
        vec[i] = hash;
        suff[i] = sum;
    }
    int ans = 0;
    for(int i=1;i<n;i++) {
        for(int j=i+1;j<n-1;j++) {
            vector<int> diff = vec[0];
            
            auto find1 = upper_bound(vec[j+1].begin()+a[i], vec[j+1].end(), 0) - vec[j+1].begin();
            auto find2 = upper_bound(vec[j+1].begin(), vec[j+1].begin()+a[j], 0) - vec[j+1].begin();
            if(find1==n+1 || find2==a[j]) {
                continue;
            }
            int cnt1 = suff[j+1][find1];
            int cnt2 = suff[j+1][0] - suff[j+1][find2];
            if(find1)
            ans += ()

        }
    }

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
