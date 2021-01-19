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
    int size;
    vector<pii> mins;       //min,count
    
    void init(int n) {
        size=1;
        while(size<n) {
            size*=2;
        }
        mins.assign(2*size,{INT_MAX,0});
    }

    void build(vector<int> &a,int x, int lx, int rx) {
        if(rx-lx==1) {
            if(lx<a.size()) {
                mins[x] = {a[lx],1};
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);

        auto left = mins[2*x+1];
        auto right = mins[2*x+2];
        if(left.ff==right.ff) {
            mins[x] = {left.ff,left.ss + right.ss};
            return;
        }
        if(left.ff<right.ff) {
            mins[x] = left;
        } else {
            mins[x] = right;
        }
    }
    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx-lx==1) {
            mins[x] = {v,1};
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }

        auto left = mins[2*x+1];
        auto right = mins[2*x+2];
        if(left.ff==right.ff) {
            mins[x] = {left.ff,left.ss + right.ss};
            return;
        }
        if(left.ff<right.ff) {
            mins[x] = left;
        } else {
            mins[x] = right;
        }
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair<int,int> lows(int l, int r, int x, int lx, int rx) {
        if(r<=lx or l>=rx) {
            return {INT_MAX,0};
        }
        else if(l<=lx && r>=rx) {
            return mins[x];
        }
        int m = (lx+rx)/2;
        auto left = lows(l, r, 2*x+1, lx, m);
        auto right = lows(l, r, 2*x+2, m, rx);
        if(left.ff==right.ff) {
            return {left.ff,left.ss + right.ss};
        }
        if(left.ff<right.ff) {
            return left;
        } else {
            return right;
        }     
    }
    pair<int,int> lows(int l, int r) {
        return lows(l, r, 0, 0, size);
    }

};

int32_t main()
{
    FIO;
    int n,m;
    cin>>n>>m;

    segtree st;
    st.init(n);

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    st.build(a);
    // debug(st.mins);
    while(m--) {
        int op;
        cin>>op;
        if(op==1) {
            int i,v;
            cin>>i>>v;
            st.set(i,v);
        } else {
            int l,r;
            cin>>l>>r;
            auto ret = st.lows(l,r);
            cout<<ret.ff<<" "<<ret.ss<<endl;
        }
        // debug(st.mins);
    }
}