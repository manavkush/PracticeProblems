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

struct segtree {
    int size=1;
    vector<int> sums;

    void init(int n) {
        while(size<n) {
            size*=2;
        }
        sums.assign(2*size,0);
    }

    void set(int i, int x, int lx, int rx) {
        if ( rx - lx == 1) {
            sums[x] = 1;
            return;
        }
        int m = (rx+lx)/2;
        if(i<m) {
            set(i, 2*x+1, lx, m);
        } else {
            set(i, 2*x+2, m, rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }
    void set(int i) {
        set(i, 0, 0, size);
    }

    int calc(int l, int r, int x, int lx, int rx) {
        if(rx<=l or r<=lx) {
            return 0;
        }
        if(l<=lx and r>=rx) {
            return sums[x];
        }
        int m = (lx+rx)/2;
        int left= calc(l, r, 2*x+1, lx, m);
        int right = calc(l, r, 2*x+2, m, rx);
        return left+right;
    }
    int calc(int l, int r) {
        if(l==r) {
            return 0;
        }
        return calc(l, r, 0, 0, size);
    }

};

int32_t main()
{
    FIO;
    int n;
    cin>>n;
    segtree st;
    st.init(n);
    vector<int> a;
    // int ans=0;
    for(int i=0;i<n;i++) {
        // debug(st.sums);
        int k;
        cin>>k;
        st.set(k-1);
        cout<<st.calc(k,n)<<" ";
    }
    // debug(st.sums);
}