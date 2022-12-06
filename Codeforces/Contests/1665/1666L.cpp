// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

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
int n,m,s;
vector<int> adj[200005];
vector<int> vis(200005, 0);
unordered_map<int,int> parent;
bool found = false;
int color = 1;

void print(vector<int> &path) {
    cout<<path.size()<<endl;
    for(int i=path.size()-1;i>=0;i--) {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void dfs(int node, int col) {
    // if((vis[node]!=0) and (vis[node]!=col)) {
    //     found = 1;
    //     cout<<"Possible\n";
    //     vector<int> path;
        
    // }
    vis[node]=col;    // currently in stack
    for(auto x: adj[node]) {
        if(found) {
            return;
        }
        // if starting node, dont consider
        if(x==s) {
            continue;
        }
        if(vis[x]==0) {
            parent[x] = node;
            dfs(x, col);
        } else if(vis[x]!=col) {
            found = 1;
            cout<<"Possible\n";
            vector<int> path1, path2;

            int curr = x;
            while(curr!=-1) {
                path1.pb(curr);
                curr = parent[curr];
            }

            path2.push_back(x);
            curr = node;
            while(curr!=-1) {
                path2.push_back(curr);
                curr = parent[curr];
            }

            print(path1);
            print(path2);
            
            return;
        } 
    }
}

void solve() {
    cin>>n>>m>>s;
    re(i,m) {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    parent[s] = -1;
    
    for(auto x: adj[s]) {
        if(found) {
            return;
        }
        if(parent.count(x)!=0) {
            found = 1;
            cout<<"Possible\n";
            vector<int> path;
            int curr = x;
            while(curr!=-1) {
                path.push_back(curr);
                curr=parent[curr];
            }
            print(path);
            cout<<2<<endl;
            cout<<s<<" "<<x<<endl;
            return;
        }
        parent[x] = s;
        dfs(x, color);
        color++;
    }
    if(!found) {
        cout<<"Impossible\n";
    }

}
int32_t main()
{
    FIO;
    int t=1;
    while(t--)
    {
        solve();    
    }
}
