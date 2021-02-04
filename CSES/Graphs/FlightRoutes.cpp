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
const int N = 1e5 + 5;
const int MAXVAL = 1e15;
vector<pii> adj[N];
vector<multiset<int>> dist(N);
int n,m,k;

void djikstra() {

    // Initializing the distances
    re(i,N) {
        re(j,10) {
            dist[i].insert(MAXVAL);
        }
    }
    debug(dist[0], dist[1]);
    dist[1].insert(0);
    debug(dist[1]);
    dist[1].erase(--dist[1].end());

    set<pii> s;
    s.insert({0,1}); // Distance, node
    while(!s.empty()) {
        // cout<<"*";
        auto p = *s.begin();
        int id = p.ss;
        int val = p.ff;

        for(auto x: adj[id]) {

            int dest = x.ff;
            int destval = x.ss;

            if( (*dist[dest].rbegin()) < (*dist[id].begin()) + destval) 
            {
                auto f = s.find({(*dist[dest].rbegin()),dest});
                if(f!=s.end()) {
                    s.erase(f);
                }
                dist[dest].insert((*dist[id].begin()) + destval);
                dist[dest].erase(--dist[dest].end());
                s.insert({(*dist[id].begin()) + destval, dest});
            }
        }
    }
    int count=0;
    for(auto x: dist[n]) {
        cout<<(x)<<" ";
        count++;
        if(count>=k) {
            break;
        }
    }
}

int32_t main()
{
    FIO;
    cin>>n>>m>>k;
    re(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    djikstra();

}