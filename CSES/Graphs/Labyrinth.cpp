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
char grid[1005][1005];
bool vis[1005][1005];

int n,m;
bool flag=0;
pii start, ending;

int dr [] = {1,-1, 0,  0};
int dc [] = {0, 0, 1, -1};

map<pii,pii> parent;    // parent of (i,j) -> k,l

bool explore(int r, int c) {
    if(r<0 || c<0) return false;
    if(r>=n || c>=m) return false;
    if(vis[r][c]) return false;
    if(grid[r][c] == '#') return false;
    return true;
}

void bfs(int i, int j) {
    queue<int> xx,yy;
    xx.push(i);
    yy.push(j);
    vis[i][j] = 1;

    while(!xx.empty()) {        
        int sx = xx.front();
        int sy = yy.front();
        xx.pop();
        yy.pop();
        if(sx == ending.ff and sy == ending.ss) {
            flag = 1;
            return;
        }
        re(i,4) {
            int rr = sx + dr[i];
            int cc = sy + dc[i];

            if(explore(rr,cc)) {
                xx.push(rr);
                yy.push(cc);
                vis[rr][cc]=1;
                parent[{rr,cc}] = {sx,sy};
            }
        }
    }
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    // vector<pii> dots;
    re(i,n) {
        re(j,m) {
            cin>>grid[i][j];
            if(grid[i][j]=='A') {
                start = {i,j};
            } else if(grid[i][j]=='B') {
                ending = {i,j};
            }
        }
    }
    int count=0;
    bfs(start.ff, start.ss);
    if(!flag) {
        cout<<"NO";
        return 0;
    } else {
        cout<<"YES\n";
        vector<pii> res;
        auto curr = ending;
        while(curr != start) {
            res.pb(curr);
            curr = parent[curr];
        }
        cout<<res.size()<<endl;
        res.pb(start);
        reverse(all(res));
        debug(res);
        for(int i=1;i<res.size();i++) {
            int dx = res[i].ff - res[i-1].ff;
            int dy = res[i].ss - res[i-1].ss;

            if(dx==1) {
                cout<<"D";
            } else if(dx==-1) {
                cout<<"U";
            } else if(dy==1) {
                cout<<"R";
            } else if(dy==-1) {
                cout<<"L";
            }
        }
    }

}