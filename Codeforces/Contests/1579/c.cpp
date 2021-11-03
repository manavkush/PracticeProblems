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
    int n,m,d;
    cin>>n>>m>>d;
    char grid[n+5][m+5];
    for(int i=0;i<n+5;i++) {
        for(int j=0;j<n+5;j++) {
            grid[i][j] = 'a';
        }
    }
    re(i,n) {
        re(j,m) {
            cin>>grid[i][j];
        }
    }
    int vis[n+1][m+1];
    memset(vis, -1, sizeof(vis));
    re(i,n) {
        re(j,m) {
            if(grid[i][j] == '*') {
                int x = i-1, y= j-1;
                int cnt1 = 0;
                int cnt2 = 0;
                while(x>=0 and y>=0 and grid[x][y] == '*') {
                    cnt1++;
                    x--;
                    y--;
                }
                x = i-1; y = j+1;
                while(x>=0 and y<m and grid[x][y] == '*') {
                    cnt2++;
                    x--;
                    y++;
                }

                x=i, y=j;
                int it = 0;
                while(x>=0 and y>=0 and grid[x][y]=='*' and it<=min(cnt1, cnt2)) {
                    vis[x][y] = max(vis[x][y], min(cnt1, cnt2));
                    x--, y--;
                    it++;
                }
                x = i, y=j;
                it=0;
                while(x>=0 and y<m and grid[x][y]=='*' and it<=min(cnt1, cnt2)) {
                    vis[x][y] = max(vis[x][y], min(cnt1, cnt2));
                    x--, y++;
                    it++;
                }
            }
        }
    }
    re(i,n) {
        re(j,m) {
            if(grid[i][j]=='*' and vis[i][j] <d) {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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