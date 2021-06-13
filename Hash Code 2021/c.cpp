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
void rec(vector<int> &res, int f, int l, int rem, int turn, int num) {
    debug(f,l,num,rem);
    if(l-f<rem) {
        if(turn==1) {
            res[l] = num;
            rec(res,f,l-1,rem-(l-f),turn^1, num+1);
        } else {
            res[f] = num;
            rec(res,f+1,l,rem-(l-f),turn^1, num+1);
        }
    } else if(l-f>=rem) {
        if(turn==1) {
            for(int i=f;i<=l;i++) {
                res[i]= num + (i-f);
            }
            for(int i=0;i<rem;i++) {
                swap(res[l-i], res[l-rem+i]);
                
            }
        } else {
            for(int i=l;i>=f;i--) {
                res[i]= num + (i-l);
            }
            for(int i=0;i<rem;i++) {
                swap(res[f+i],res[f+rem-i]);
                
            }
        }
        return;
    }
}

void solve(int k) {
    int n,c;
    
    cin>>n>>c;
    if((c>n*(n+1)/2) or (c<n)){
        cout<<"Case #"<<k<<": "<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> res(n);
    int f=0,l=n-1; 
    rec(res,f,l,c-n+1, 1, 1);
    cout<<"Case #"<<k<<": ";
    for(auto x: res) {
        cout<<x<<" ";
    }
    cout<<endl;
    
}
int32_t main()
{
    FIO;
    int t=1;
    cin>>t;
    re(k,t)
    {
        solve(k+1);
    }
}