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
    int high = *max_element(all(a));
    int ans = 0;
    map<pii,int> hash;
    hash[{0,1}] = 0;
    hash[{1,0}] = 0;

    for(int i=0;i<n;i++) {
        int x = high-a[i];
        ans += (x/3)*2;
        if(x%3==0) {
            continue;
        } else {
            // odd day remaining
            if(x%3==1) {
                // if no even days rem
                if(hash[{0,1}]==0) {
                    hash[{1,0}]++;
                } else {
                    hash[{0,1}]--;
                    ans+=2;
                }
            } else {
                if(hash[{1,0}]==0) {
                    hash[{0,1}]++;
                } else {
                    hash[{1,0}]--;
                    ans+=2;
                }
            }
        }

    }
    debug(ans, hash);
    if(hash[{0,1}]==0) {
        ans += 2*(hash[{1, 0}])-1;
    } else {
        if(hash[{0,1}]%3==0) {
            ans += 4*(hash[{0,1}]/3);
        } else if(hash[{0,1}]%3==1) {
            ans += 2+4*(hash[{0,1}]/3);

        } else {
            ans += 3+4*(hash[{0,1}]/3);
        }
    }
    cout<<ans<<endl;
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
