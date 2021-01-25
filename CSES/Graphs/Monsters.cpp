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
int dis[1005][1005];
int d[1005][1005];
vector<pii> monsters;

int n,m;
bool flag=0;
pii start, ending;

int dr [] = {1,-1, 0,  0};
int dc [] = {0, 0, 1, -1};

map<pii,pii> parent;    // parent of (i,j) -> k,l

bool explore(int r, int c) {
    if(r<0 || c<0) return false;
    if(r>=n || c>=m) return false;
    if(grid[r][c] == '#') return false;
    return true;
}

void bfs() {
    queue<int> xx,yy;
    for(auto x: monsters) {
        xx.push(x.ff);
        yy.push(x.ss);
        dis[x.ff][x.ss] = 0;
        vis[x.ff][x.ss] = 1;
    }
    // xx.push(i);
    // yy.push(j);
    // vis[i][j] = 1;
    // dis[i][j] = 0;
    while(!xx.empty()) {
        int sx = xx.front();
        int sy = yy.front();
        xx.pop();
        yy.pop();
        
        re(i,4) {
            int rr = sx + dr[i];
            int cc = sy + dc[i];

            if(explore(rr,cc) and (!vis[rr][cc])) {
                    vis[rr][cc] = 1;
                    dis[rr][cc] = dis[sx][sy]+1;
                    xx.push(rr);
                    yy.push(cc);
            }
        }
    }
}

void bfsman(int i, int j) {
    queue<int> qr, qc;
    qr.push(i);
    qc.push(j);
    d[i][j] = 0;
    vis[i][j] = 0;
    while(!qr.empty()) {
        int sx = qr.front();
        int sy = qc.front();
        qr.pop(); qc.pop();

        re(p,4) {
            int rr = sx + dr[p];
            int cc = sy + dc[p];
            if(explore(rr,cc) and (!vis[rr][cc])) {
                parent[{rr,cc}] = {sx,sy};
                qr.push(rr);
                qc.push(cc);
                vis[rr][cc] = 1;
                d[rr][cc] = d[sx][sy] + 1;
            }
        }
    }
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    re(i,n) {
        re(j,m) {
            dis[i][j]=INT_MAX;
            d[i][j] = INT_MAX;
        }
    }
    re(i,n) {
        re(j,m) {
            cin>>grid[i][j];
            if(grid[i][j]=='A') {
                start = {i,j};
            } else if(grid[i][j]=='M') {
                monsters.pb({i,j});
            }
        }
    }
    bfs();

    // Second time bfs (for man)
    re(i,1005) {
        re(j,1005) {
            vis[i][j] = 0;
        }
    }
    bfsman(start.ff, start.ss);

    bool flag = 0;
    pii ans;
    vector<pair<int,int>> collect;

    re(i,n) {
        if(grid[i][0]!='#') {
            collect.pb({i,0});
        }
        if(grid[i][m-1]!='#') {
            collect.pb({i,m-1});
        }
    }
    re(i,m) {
        if(grid[0][i] != '#') {
            collect.pb({0,i});
        }
        if(grid[n-1][i]!='#') {
            collect.pb({n-1,i});
        }
    }
    for(auto x: collect) {
        if(d[x.ff][x.ss] == INT_MAX) {
            continue;
        } else if(dis[x.ff][x.ss] == INT_MAX) {
            flag = 1;
            ans = x;
            break;
        } else if(d[x.ff][x.ss]<dis[x.ff][x.ss]) {
            flag = 1;
            ans = x;
            break;
        }
    }


    if(!flag) {
        cout<<"NO";
        return 0;
    } else {
        cout<<"YES\n";
        vector<pii> res;
        auto curr = ans;
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