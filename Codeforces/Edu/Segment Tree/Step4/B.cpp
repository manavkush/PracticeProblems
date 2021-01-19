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
int r;
struct node {
    int a, b, c, d;
};


struct segtree {
    int size=1;
    vector<node> sums;

    node NEUTRAL_ELEMENT = {1,0,0,1};
    
    void init(int n) {
        while(size<n) {
            size*=2;
        }
        sums.assign(2*size,NEUTRAL_ELEMENT);
    }

    node merge(node &x, node &y) {
        node temp;
        temp.a = ((x.a * y.a) % r + (x.b * y.c)%r) % r;
        temp.b = ((x.a * y.b) % r + (x.b * y.d)%r) % r;
        temp.c = ((x.c * y.a) % r + (x.d * y.c)%r) % r;
        temp.d = ((x.c * y.b) % r + (x.d * y.d)%r) % r;
        return temp;
    }

    void build(vector <node> &a, int x, int lx, int rx) {
        if(rx-lx==1) {
            if(lx<a.size()) {
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);

        sums[x] = merge(sums[2*x+1], sums[2*x+2]);
    }
    void build(vector <node> &a) {
        build(a, 0, 0, size);
    }

    // void set(int i, int v, int x, int lx, int rx) {
    //     if(rx-lx==1) {
    //         sums[x] = v;
    //         return;
    //     }
    //     int m = (rx + lx)/2;
    //     if(i<m)
    //         set(i, v, 2*x+1, lx, m);
    //     else 
    //         set(i, v, 2*x+2, m, rx);

    //     sums[x] = sums[2*x+1] + sums[2*x+2];
    // }
    // void set(int i, int v) {
    //     set(i, v, 0, 0, size);
    // }

    node calc(int l, int r, int x, int lx, int rx) {
        if(r<=lx || rx<=l) {
            return NEUTRAL_ELEMENT;
        } 
        if(l<=lx and r>=rx) {
            return sums[x];
        }
        int m= (lx+rx)/2;
        node left = calc(l,r, 2*x+1, lx, m);
        node right = calc(l,r, 2*x+2, m, rx);

        return merge(left, right);
    }
    node calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};

int32_t main()
{
    FIO;
    int n,m;
    cin>>r>>n>>m;
    segtree st;
    st.init(n+1);
    vector<node> a(n);
    re(i,n) {
        cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
    }
    st.build(a);
    int i=0;
    // for(auto x: st.sums) {
    //     cout<<i<<endl;
    //     i++;
    //     cout<<x.a<<","<<x.b<<"\n"<<x.c<<","<<x.d<<endl;
    //     cout<<"\n";
    // }
    while(m--) {
        int l, r;
        cin>>l>>r;
        l--;
        cout<<endl;
        node temp = st.calc(l,r);
        cout<<temp.a<<" "<<temp.b<<endl;
        cout<<temp.c<<" "<<temp.d<<endl;
    }
}