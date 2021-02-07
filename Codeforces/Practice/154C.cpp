#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
// #define int long long
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
int n;
int r1,r2,c1,c2;
vi a;
const int N = 1e5+1;

vector<vector<int> > dist(105,vector<int> (N, 0));
// int dist[101][N];
vector<vector<int>> vis(105,vector<int> (N, 0));

int dr [] = {1, -1, 0 , 0};
int dc [] = {0, 0 , 1, -1};

bool explore(int rr, int cc) {
    if(rr<0 or cc<0 or rr>=n) {
        return false;
    } 
    if(cc>a[rr]) {
        cc = a[rr];
    }
    if(vis[rr][cc]) {
        return false;
    }
    return true;
}

void bfs() {
    queue<int> rows,cols;
    rows.push(r1);
    cols.push(c1);
    debug(r1,c1,r2,c2);
    vis[r1][c1] = 1;
    while(!rows.empty()) {
        int r = rows.front();
        int c = cols.front();
        // debug(r,c);
        if((r==r2) and (c==c2)) {
            return;
        }
        rows.pop();
        cols.pop();

        re(i,4) {
            int rr = r+dr[i];
            int cc = c+dc[i];
            if(explore(rr,cc)) {
                if(cc>a[rr]) {
                    cc = a[rr];
                }
                vis[rr][cc] = 1;
                dist[rr][cc] = dist[r][c]+1;
                rows.push(rr);
                cols.push(cc);
            }
        }
    }
}

int32_t main()
{
    FIO;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    cin>>n;
    a.resize(n);
    re(i,n) {
        cin>>a[i];
    }
    // memset(dist, -1, sizeof(dist));
    
    cin>>r1>>c1>>r2>>c2;
    debug(r1,c1,r2,c2);
    r1--;
    r2--;
    c1--;
    c2--;
    // dist[r1][c1] = 0;
    bfs();
    // re(i,n) {
    //     debug(dist[i]);
    // } 
    cout<<dist[r2][c2]<<endl;
    
}
