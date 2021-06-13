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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n,m;
bool vis[51][51];
char grid[51][51];
bool correct(int x, int y) {
    if(x<0 or y<0) {
        return false;
    }
    if(x>=n or y>=m) {
        return false;
    }
    return true;
}
bool explore(int x,int y) {
    re(i,4) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(correct(xx,yy)) {
            if(grid[xx][yy]=='#') {
                continue;
            } 
            if(grid[xx][yy]=='.') {
                grid[xx][yy]='#';
            } 
            if(grid[xx][yy]=='G') {
                return false;
            }
        }
    }
    return true;
}
void bfs(int sx, int sy) {
    queue<int> r,c;
    r.push(sx);
    c.push(sy);
    while(!r.empty()) {
        int x,y;
        x=r.front();
        y=c.front();
        r.pop();c.pop();

        re(i,4) {
            int xx=x+dx[i];
            int yy=y+dy[i];
            
            if(!correct(xx,yy)) continue;
            if(vis[xx][yy]==1)  continue;
            if(grid[xx][yy]=='#')  continue;

            vis[xx][yy] = 1;
            r.push(xx); c.push(yy);
        }
    }
}
void solve() {
    cin>>n>>m;
    re(i,51) {
        re(j,51) {
            vis[i][j]=0;
        }
    }
    vector<pii> bads,goods;
    re(i,n) {
        re(j,m) {
            cin>>grid[i][j];
            if(grid[i][j]=='B') {
                bads.pb({i,j});
            } else if(grid[i][j]=='G') {
                goods.pb({i,j});
            }
        }
    }
    // if(grid[n-1][m-1]=='#' and (!goods.empty())) {
    //     cout<<"No\n";
    //     return;
    // }
    for(auto x: bads) {
        int f = x.ff;
        int s = x.ss;
        if(!explore(f,s)) {
            cout<<"No\n";
            return;
        }
    }
    if(grid[n-1][m-1]!='#')
        bfs(n-1,m-1);
    for(auto x: bads) {
        int f = x.ff;
        int s = x.ss;
        if(vis[f][s]) {
            cout<<"No\n";
            return;
        }
    }
    for(auto x: goods) {
        int f = x.ff;
        int s = x.ss;
        if(!vis[f][s]) {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
    return;
    

}
int32_t main()
{
    FIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}