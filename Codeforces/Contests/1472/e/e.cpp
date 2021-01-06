#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
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
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
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
const int N = 2e5 + 5;
int n;
struct data {
    int h, w, idx;
};

data a[N];

bool comp(data &x, data &y) {
    if (x.w != y.w) {
        return x.w < y.w;
    } else {
        return x.h > y.h;
    }
}
int32_t main() {
    FIO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vi ans(n,-2);
        vector<data> vec;
        re(i, n) {
            data temp;
            cin >> a[i].h >> a[i].w;
            a[i].idx = i;

            temp.h = a[i].w;
            temp.w = a[i].h;
            temp.idx = i;

            vec.pb(a[i]);
            vec.pb(temp);
        }
        sort(all(vec), comp);
        int Minheight=1e18;
        int element=-1;

        for(auto x:vec) {
            int w=x.w;
            int h=x.h;
            int idx=x.idx;

            if(h>Minheight ) {
                ans[idx]=element;
                // debug(id,hig,Minheight,element);
                // debug(x.h,x.w,x.idx);
            } else if(h<Minheight) {
                Minheight=h;
                element=idx;
            }
        }
        for(auto x:ans) {
            cout<<x+1<<" ";
        }
        cout<<endl;
        // for(auto x:vec) {
        //     cout<<x.w<<" "<<x.h<<" "<<x.idx<<endl;
        // }
    }


}