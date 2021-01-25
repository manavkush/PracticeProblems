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
// We'll make 2 djikstra calls:
// First from the node 1 on the graph
// Second from the node n on the inverted graph
// Then we'll check for each each if relaxing it would be optimal or not'
int n,m;

const int MAXVAL = 1e16;
const int N = 1e5 +5;
// vector<pii> adj[N];    // normal graph
// vector<pii> inv[N];    // inverted graph
vector<pii> *adj;    // normal graph
vector<pii> *inv;    // inverted graph

// vector<int> vis(N,0);

vector<int> dis1(N,MAXVAL);
vector<int> dis2(N,MAXVAL);

void dijsktra(int src, vector<pii> *adj, vector<int> &dist) {
    // cout<<"*\n";
    dist[src]=0;

    set<pii>s;
    s.insert({0,src});

    while(!s.empty())
    {
        // cout<<"*";
        auto  p = *(s.begin());
        int id = p.ss;
        int val = p.ff;

        s.erase(s.begin());

        for(auto x : adj[id]) {
            
            int destId = x.ff;
            int destVal = x.ss;

            if(dist[destId] >dist[id] + destVal) {
                auto f = s.find(mp(dist[destId],destId));
                if(f!=s.end()) {
                    s.erase(f);
                }
                long long targVal = dist[id] + destVal;
                dist[destId] = targVal;
                s.insert(mp(targVal,destId));
            }

        }
    } 
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    adj = new vector<pii> [n+2];
    inv = new vector<pii> [n+2];
    re(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        inv[b].pb({a,c});
    }
    dijsktra(1,adj,dis1);
    // cout<<"@";
    dijsktra(n,inv,dis2);
    int ans = MAXVAL;
    for(int i=1;i<=n;i++) {
        for(auto x: adj[i]) {
            ans = min(ans, dis1[i] + dis2[x.ff] + (x.ss/2));    // We're trying relaxing each edge
        }
    }
    cout<<ans<<endl;
}