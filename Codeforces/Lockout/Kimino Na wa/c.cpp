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
// If cycle present ans: No
// Else answer : Yes
// topsort the graph. Add the undirected edges from high to low priority
const int N=2e5+5;
vector<int> adj[N];
vector<int> vis(N,0);
vector<pair<int,int>> edgelist;
vector<int> sorted;
int n,m;

// Checking if directed graph is cyclic
bool check(int s) {
    vis[s]=2;
    for(auto x:adj[s]) {
        if(vis[x]==2) {
            return true;
        } else if(vis[x]==0 && check(x)) {
            return true;
        }
    }
    vis[s]=1;
    return false;
}

void topsort(int s) {
    for(auto x:adj[s]) {
        if(vis[x]==0) {
            vis[x]=1;
            topsort(x);
        }
    }
    sorted.pb(s);
}

int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        re(i,m) {
            int t,x,y;
            cin>>t>>x>>y;
            if(t) {
                adj[x].pb(y);
            } else {
                edgelist.pb({x,y});
            }
        }
        int flag=0;
        for(int i=1;i<=n;i++) {
            if(vis[i]==0 && check(i)) {
                flag=1;
                break;
            }
        }
        if(flag) {
            cout<<"NO\n";       // Graph cyclic
        } else {
            cout<<"YES\n";      // Graph acyclic
            re(i,n+1) {
                vis[i]=0;
            }

            // topsorting
            for(int i=1;i<=n;i++) {
                if(vis[i]==0) {
                    vis[i]=1;
                    topsort(i);
                }
            }
            // Now maping the node to the priority
            map<int,int> priority;
            for(int i=0;i<sorted.size();i++) {
                priority[sorted[i]]=i;
            }
            // debug(sorted);
            // debug(priority);
            for(auto x:edgelist) {
                int u=x.ff;
                int v=x.ss;
                if(priority[u]>priority[v]) {   // Assigning edge from high priority to low priority
                    adj[u].pb(v);
                }
                else {
                    adj[v].pb(u);
                }
            }
            for(int i=1;i<=n;i++) {
                for(auto x:adj[i]) {
                    cout<<i<<" "<<x<<endl;
                }
            }
        }




        re(i,n+1) {
            adj[i].clear();
            vis[i]=0;
        }
        edgelist.clear();
        sorted.clear();
        
    }
}
