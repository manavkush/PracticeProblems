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
const int N=1e5;
int n;
vector<int> a;
vector<pair<int,int>> *adj;
vector<int> sum;
vector<int> vis;
// vector<int> cnt;    // no of nodes below

int dfs(int s) {
    vis[s]=1;
    int count=1;
    for(auto x:adj[s]) {
        if(vis[x.first]) {
            continue;
        }
        if(sum[x.ff]>a[x.ff]) {
            continue;
        }
        else {
            count+=dfs(x.ff);
        }
    }
    return count;

}

void pref(int s) {
    vis[s]=1;
    for(auto x: adj[s]) {
        //
        int num=x.first;
        int weight=x.second;

        if(vis[num]) {
            continue;
        } else {
            sum[num] = max(weight + sum[s], weight);
            pref(num);
        }
    }
}

int32_t main()
{
    FIO;
    cin>>n;
    a.resize(n+1);
    sum.resize(n+1,0);
    vis.resize(n+1,0);
    // count.resize(n+1,0);
    re(i,n) {
        cin>>a[i+1];
    }
    adj = new vector<pair<int,int>> [n+1];
    // adj.resize(n+1);
    re1(i,1,n-1) {
        int p,c;
        cin>>p>>c;
        adj[i+1].pb({p,c});
        adj[p].pb({i+1,c});
    }
    // re1(i,1,n) {
    //     cout<<i<<": ";
    //     for(auto x:adj[i]) {
    //         cout<<x.ff<<","<<x.ss<<" ";
    //     }
    //     cout<<endl;
    // }
    
    debug(sum);
    pref(1);
    debug(sum);
    debug(a);
    re(i,vis.size()) {
        vis[i]=0;
    }
    int ct=0;
    
    cout<<n-dfs(1)<<endl;
}
