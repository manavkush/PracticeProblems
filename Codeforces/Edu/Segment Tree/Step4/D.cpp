#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
// #define int long long
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

struct node {
    long long inv;
    vector<int> freq;
};


struct segtree {
    int size=1;
    vector<node> sums;

    node NEUTRAL_ELEMENT;

    void neutral() {    // Making the neutral element
        NEUTRAL_ELEMENT.freq.assign(41,0);
        NEUTRAL_ELEMENT.inv = 0;
    }
    
    // Merging the two child nodes
    node merge(node &a, node &b) {
        node temp = NEUTRAL_ELEMENT;
        for(int i=1;i<=40;i++) {
            temp.freq[i] = a.freq[i] + b.freq[i];
        }
        temp.inv = 0;
        // temp.inv += a.inv;
        // temp.inv += b.inv;
        for(int i=1;i<=40;i++) {
            if((!a.freq[i]) and (!b.freq[i])) {
                continue;
            } else {
                temp.inv ++;
            }
        }
        return temp;
    }

    void init(int n) {
        while(size<n) {
            size*=2;
        }
        sums.assign(2*size,NEUTRAL_ELEMENT);
    }
    
    void build(vector <int> &a, int x, int lx, int rx) {
        // debug(x,lx,rx);
        if(rx-lx==1) {
            if(lx<a.size() ) {
                sums[x] = NEUTRAL_ELEMENT;
                sums[x].freq[a[lx]] = 1;
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);

        sums[x] = merge (sums[2*x+1], sums[2*x+2]);
    }
    void build(vector <int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx-lx==1) {
            sums[x] = NEUTRAL_ELEMENT;
            sums[x].freq[v] = 1;
            return;
        }
        int m = (rx + lx)/2;
        if(i<m)
            set(i, v, 2*x+1, lx, m);
        else 
            set(i, v, 2*x+2, m, rx);

        sums[x] = merge(sums[2*x+1] ,sums[2*x+2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

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

        return merge(left , right);
    }
    node calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};  

int32_t main()
{
    FIO;
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    re(i,n) {
        cin>>a[i];
    }
    segtree st;
    st.neutral();
    st.init(n+1);
    st.build(a);

    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int l, r;
            cin>>l>>r;   l--;
            node ret = st.calc(l,r);
            cout<<ret.inv<<endl;
        } else {
            int x,y;
            cin>>x>>y;
            x--;
            st.set(x,y);
        }
    }
}