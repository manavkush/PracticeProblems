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
vector<string> mat;
int n,m;
int dp[51][51];
bool vis[51][51];

int dr[]={1,-1,0,0,1,-1,-1,1};
int dc[]={0,0,1,-1,1,1,-1,-1};

// int dfs_util(int x,int y) {
//     if(vis[])
// }

int dfs(int x,int y,char c) {
    
    if(x<0||y<0||x>=n||y>=m) {
        return 0;
    }
    if(mat[x][y]!=c) {  // If the character is not the one passed
        return 0;
    }
    if(character)
    if(vis[x][y]) {
        return dp[x][y];
    }
    vis[x][y]=1;
    char c2=c+1;
    int ans=0;
    for(int i=0;i<8;i++) {
        int call=dfs(x+dr[i],y+dc[i],c2);
        ans=max(call,ans);
    }
    dp[x][y]=ans;
    return ans;    
}

int32_t main()
{
    FIO;
    cin>>n>>m;
    mat.resize(n);
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    re(i,n) {
        string str;
        cin>>mat[i];
        set<pii> st;
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='A') {
                st.insert({i,j});
            }
        }
        int ans=0;
        while(!st.empty()) {
            auto top=st.begin();
            int x=top->first;
            int y=top->second;
            int call=dfs(x,y,'A');
            ans=max(ans,call);
        }
        
    }
    
}
