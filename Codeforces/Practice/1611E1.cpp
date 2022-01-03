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
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> adj[n+1];
    vi a(k);
    vector<int> dist_friends(n+1, INT_MAX);
    vector<int> dist_me(n+1, INT_MAX);
    vector<int> vis(n+1, 0);
    queue<int> q;
    re(i,k) {
        cin>>a[i];
        q.push(a[i]);
        dist_friends[a[i]] = 0;
        vis[a[i]] = 1;
    }
    re(i,n-1) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dist_me[1] = 0;
    int curr = q.size();
    int dist = 0;
    // mutlisource
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        curr--;

        dist_friends[top] = dist;
        for(auto x: adj[top]) {
            if(!vis[x]) {
                q.push(x);
                vis[x] = 1;
            }
        }
        if(curr == 0) {
            curr = q.size();
            dist++;
        }
    }

    // Single source
    vis = vector<int> (n+1, 0);
    q.push(1);
    dist = 0;
    curr = 1;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        curr--;

        dist_me[top] = dist;
        for(auto x: adj[top]) {
            if(!vis[x]) {
                q.push(x);
                vis[x] = 1;
            }
        }
        if(curr == 0) {
            curr = q.size();
            dist++;
        }
    }

    for(int i=2;i<=n;i++) {
        if(adj[i].size()==1 and dist_me[i]<dist_friends[i]) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO\n";
    return;    
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}