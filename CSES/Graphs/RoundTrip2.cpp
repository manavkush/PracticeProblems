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
int n,m;
const int N = 1e5+5;
vector<int> adj[N];
vector<int> vis(N,0);

stack<int> st;
int start = -1;
int ending = -1;

bool dfs(int s) {
    vis[s] = 2;
    st.push(s);
    for(auto x: adj[s]) {
        if(vis[x]==0 and dfs(x)) {
            return true;
        }
        else if(vis[x]==2) {
            start = x;
            ending = s;
            return true;
        }
    }
    vis[s] = 1;
    st.pop();
    return false;
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    re(i,m) {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    vector<int> ans;
    bool flag = 0;
    re(i,N) {
        if(vis[i]==0 and dfs(i)) {
            ans.pb(start);
            while(st.top()!=start) {
                ans.pb(st.top());
                st.pop();
            }
            ans.pb(st.top());
            break;
        }
    }
    if(ans.size()==0) {
        cout<<"IMPOSSIBLE";
    } else {
        reverse(all(ans));
        cout<<ans.size()<<endl;
        for(auto x: ans) {
            cout<<x<<" ";
        }
    }
}
