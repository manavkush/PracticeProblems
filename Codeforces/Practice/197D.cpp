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

struct item {
    int val;
    int turn;
};

struct segtree {
    
    int size;   // We need closest power of 2 greater than or equal to n
    vector<item> values;

    item NEUTRAL_ELEMENT = {0,0};
    // If we add this element to any other element the result would be the same.

    item merge(item &a, item &b) {
        item temp = NEUTRAL_ELEMENT;
        if(a.turn == 1) {
            // debug(a.val^b.val);
            temp.val = (a.val ^ b.val);
        } else {
            temp.val = (a.val|b.val);
        }
        temp.turn = (a.turn^1);
        return temp;
    }

    void init(int n) {
        size=1;
        while(size<n) size*=2;
        values.assign(2*size,{0,0});
    }

    void build(vector <int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if (lx < (int)a.size()) {
                values[x] = {a[lx],0};
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);

        // debug("#",values[2*x+1].val, values[2*x+1].val);
        values[x] = merge(values[2*x+1], values[2*x+2]);
        // debug("*",values[x].turn, values[x].val);
    }
    void build(vector <int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] = {v,0};
            return;
        }
        int m = (lx + rx)/2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    item calc(int l, int r, int x, int lx, int rx) {
        if(l>=rx || lx>=r) {
            return NEUTRAL_ELEMENT;
        } 
        if(l<=lx && r>=rx) {
            return values[x];
        }
        int m = (lx+rx)/2;
        item left = calc(l,r,2*x+1,lx,m);
        item right = calc(l,r,2*x+2,m,rx);
        return merge(left, right);
    }
    item calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    segtree st;
    n = (1<<n);
    // debug(n);
    st.init(n);
    
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        int v;
        cin >> a[i]; 
    }
    st.build(a);
    while(m--) {
        int i, v;
        cin >> i >> v;
        i--;
        st.set(i, v);
        cout<<(st.values[0].val)<<endl;
        }
    return 0;
}