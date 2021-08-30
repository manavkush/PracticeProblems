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
class node {
    public:
    int odd, even, sum;
    node() {
        this->odd = 0;
        this->even = 0;
        this->sum = 0;
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    vector<node> pref(n+1);
    re(i,n) {
        pref[i+1] = pref[i];
        if(str[i]=='+') {
            if(i&1) pref[i+1].sum--;
            else pref[i+1].sum ++;
        } else {
            if(i&1) pref[i+1].sum++;
            else pref[i+1].sum--;
        }
        // if(i&1) {
        //     pref[i+1].odd += -1*(str[i]=='+'? 1: -1);
        // } else {
        //     pref[i+1].even += 1*(str[i]=='+'? 1: -1);
        // }
    }
    re(i,q) {
        int l, r;
        cin>>l>>r;
        if(pref[r].sum-pref[l-1].sum==0) {
            cout<<0<<endl;
            continue;
        } else if((r-l+1)&1) {
            cout<<1<<endl;
        } else {
            cout<<2<<endl;
        }
    }
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}