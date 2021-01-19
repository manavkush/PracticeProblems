// codeforces 377A
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
char maze[505][505];
int vis[505][505];
int n,m,k;
int cnt=0;

bool explore(int r, int c) {
    if(r<0||c<0) {
        return false;
    } else if(r>=n || c>=m) {
        return false;
    } else if(maze[r][c]=='#') {
        return false;
    } else if (vis[r][c]==1) {
        return false;
    } else  {
        return true;
    }
}

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void dfs(int sx,int sy) {
    vis[sx][sy]=1;
    re(i,4) {
        int rr = sx+dr[i];
        int cc = sy+dc[i];
        if(explore(rr,cc)) {
            dfs(rr,cc);
        }
    }
    if(cnt>=k) {
        return;
    } else {
        maze[sx][sy]='X';
        cnt++;
    }
}

int32_t main()
{
    FIO;
    // int n,m,k;
    cin>>n>>m>>k;
    memset(vis,0,sizeof(vis));
    pair <int,int> source;
    re(i,n) {
        re(j,m) {
            cin>>maze[i][j];
            if(maze[i][j]=='.') {
                source.ff=i;
                source.ss=j;
            }
        }
    }
    dfs(source.ff,source.ss);
    
    re(i,n) {
        re(j,m) {
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}