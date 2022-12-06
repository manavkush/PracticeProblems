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
vector<int> state;
queue<int> u;
int curr = 0;

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    
    state.assign(n+1, 0);
    vector<int> adj[n+1];
    // cout<<"*"<<" ";

    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=0;i<q;i++) {
        int a,b;
        cin>>a>>b;
        if(a==1) {
            if(state[b]==0) {
                state[b] = 1;
                u.push(b);
            }
            
        } else if(a==2) {
            // run bfs
            int time = 0;
            int nodes = u.size();
            while(!u.empty() and time!=b) {
                int top = u.front();
                u.pop();
                nodes--;
                for(auto x: adj[top]) {
                    if(state[x]) {
                        continue;
                    } else {
                        state[x] = 1;
                        u.push(x);
                    }
                }
                if(nodes==0) {
                    time++;
                    if(time >= b) {
                        break;
                    }
                    nodes = u.size();
                }
            }
        } else {
            if(state[b]) {
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
    }
}

int32_t main()
{
    FIO;
    solve();
}