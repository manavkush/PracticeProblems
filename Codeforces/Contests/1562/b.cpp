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
int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string n;
        cin>>n;
        set<char> s = {'1', '4', '6', '8', '9'};
        // set<string> fnd = {}
        
        int flag = 0;
        char ans;
        string cat;
        for(int i=0;i<k;i++) {
            if(s.find(n[i])!=s.end()) {
                flag = 1;
                ans = n[i];
                break;
            }
        }
        if(flag) {
            cout<<1<<endl;
            cout<<ans<<endl;
            continue;
        } else {
            string res;
            cout<<2<<endl;
            vector<int> a[10];
            for(int i=0;i<k;i++) {
                if(n[i]=='2') {
                    a[2].pb(i);
                } 
                if(n[i]=='3') {
                    a[3].pb(i);
                }
                if(n[i]=='5') {
                    a[5].pb(i);
                }
                if(n[i]=='7') {
                    a[7].pb(i);
                }
            }
            for(int i=2;i<10;i++) {
                if(a[i].size()>1) {
                    res = to_string(i)+to_string(i);
                    // res = res+res;
                    // debug(i, res);
                    flag=1;
                    break;
                }
            }
            if(flag) {
                cout<<res<<endl;
                continue;
            }
            if((!a[2].empty() and !a[5].empty()) and a[2][0]<a[5][0]) {
                cout<<25<<endl;
                continue;
            }
            if((!a[2].empty() and !a[7].empty()) and a[2][0]<a[7][0]) {
                cout<<27<<endl;
                continue;
            }
            if((!a[3].empty() and !a[2].empty()) and a[3][0]<a[2][0]) {
                cout<<32<<endl;
                continue;
            }
            if((!a[3].empty() and !a[5].empty()) and a[3][0]<a[5][0]) {
                cout<<35<<endl;
                continue;
            }
            if((!a[5].empty() and !a[2].empty()) and a[5][0]<a[2][0]) {
                cout<<52<<endl;
                continue;
            }
            if((!a[5].empty() and !a[7].empty()) and a[5][0]<a[7][0]) {
                cout<<57<<endl;
                continue;
            }
            if((!a[7].empty() and !a[2].empty()) and a[7][0]<a[2][0]) {
                cout<<72<<endl;
                continue;
            }
            if((!a[7].empty() and !a[5].empty()) and a[7][0]<a[5][0]) {
                cout<<75<<endl;
                continue;
            }
        }
    }
}