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
    int r,g,b;
    cin>>r>>g>>b;
    if(b > max(r,g)+1 || r==0 || g==0) {
        cout<<-1<<endl;
        return;
    }
    string str;
    if(r<g) {
        str += 'R';
        for(int i=0;i<g;i++) {
            str += 'G';
        }
        for(int i=0;i<b;i++) {
            str += 'B';
        }
        for(int i=1;i<r;i++) {
            str += 'R';
        }
        cout<<str<<endl;
        for(int i=0;i<g;i++) {
            cout<<"1 "<<i+2<<endl;
        }
        for(int i=1;i<=(min(b,g));i++) {
            cout<<i+1<<" "<<i+g+1<<endl;
        }
        if(b>g) {
            cout<<1<<" "<<g+b+1<<endl;
        }
        for(int i=1;i<r;i++) {
            cout<<1<<" "<<g+b+1+i<<endl;
        }
    } else {
        str += 'G';
        for(int i=0;i<r;i++) {
            str += 'R';
        }
        for(int i=0;i<b;i++) {
            str += 'B';
        }
        for(int i=1;i<g;i++) {
            str += 'G';
        }
        cout<<str<<endl;
        for(int i=0;i<r;i++) {
            cout<<"1 "<<i+2<<endl;
        }
        for(int i=1;i<=(min(b,r));i++) {
            cout<<i+1<<" "<<i+r+1<<endl;
        }
        if(b>r) {
            cout<<1<<" "<<r+b+1<<endl;
        }
        for(int i=1;i<g;i++) {
            cout<<1<<" "<<r+b+1+i<<endl;
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