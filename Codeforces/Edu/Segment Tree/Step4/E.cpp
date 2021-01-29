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

// struct int  {
//     long long inv;
//     vector<int> freq;
// };


struct segtree {
    int size=1;
    vector<int > sums;
    
    // Merging the two child int s
    int  merge(int  &a, int  &b) {
        
    }

    void init(int n) {
        while(size<n) {
            size*=2;
        }
        sums.assign(2*size,INT_MAX);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx-lx==1) {
            sums[x] = v;
            return;
        }
        int m = (rx + lx)/2;
        if(i<m)
            set(i, v, 2*x+1, lx, m);
        else 
            set(i, v, 2*x+2, m, rx);

        sums[x] = min(sums[2*x+1] ,sums[2*x+2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // void earthquake(int l, int r, int p, int x, int lx, int rx) {
    //     if()
    // }
    // void earthquake(int l, int r, int p) {

    // }

    int  calc(int l, int r, int p, int x, int lx, int rx) {
        if(r<=lx || rx<=l) {
            return 0;
        } 
        if(l<=lx and r>=rx) {
            if(sums[x] > p)
                return 0;
        }
        if(rx-lx==1) {
            sums[x] = INT_MAX;
            return 1;
        }
        
        int m= (lx+rx)/2;
        int  left = calc(l,r, p, 2*x+1, lx, m);
        int  right = calc(l,r, p, 2*x+2, m, rx);
        sums[x] = min(sums[2*x+1], sums[2*x+2]);
        return left + right;
    }
    int  calc(int l, int r, int p) {
        return calc(l, r, p, 0, 0, size);
    }
};  

int32_t main()
{
    FIO;
    int n,q;
    cin>>n>>q;
    segtree st;
    st.init(n+1);
    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int i,h;
            cin>>i>>h;
            st.set(i,h);
        } else {
            int l,r,p;
            cin>>l>>r>>p;
            cout<<st.calc(l,r,p)<<endl;
            // st.set()
            // debug(st.sums);
        }
    }
}