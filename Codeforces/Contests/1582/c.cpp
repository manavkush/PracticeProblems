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
int util(string &s, int n, int i, int f, char c, int cnt) {
    // debug(i, f, c, cnt);
    if(i>=f) {
        return cnt;
    }
    if(s[i]==s[f]) {
        return util(s, n, i+1, f-1, c, cnt);
    } else {
        if(c=='*') {
            int ans = min(util(s, n, i+1, f, s[i], cnt+1), util(s, n, i, f-1, s[f], cnt+1));
            return ans;
        } else {
            if(s[i]!=c and s[f]!=c) {
                return INT_MAX;
            }
            int a1 = INT_MAX, a2 = INT_MAX;
            if(s[i]==c) {
                a1 = util(s, n, i+1, f, c, cnt+1);
            } 
            if(s[f]==c) {
                a2 = util(s, n, i, f-1, c, cnt+1);
            }
            return min(a1, a2);
        }

    }
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = util(s, n, 0, n-1, '*', 0);
    if(ans == INT_MAX) {
        cout<<-1<<endl;
    } else {
        cout<<ans<<endl;
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