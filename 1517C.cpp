// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

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
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int> (n, 0));
    vi a(n+1);
    map<int,int> freq;
    re(i,n) {
        cin>>a[i];
        grid[i][i] = a[i];
        freq[a[i]]++;
    }
    bool flag;
    

    for(int diags =n-1; diags>0; diags--) {
        int i=n-1;  // row
        int j=diags;   // col
        for(;i>=0 and j>=0;j--,i--) {
            int el = grid[i][j];
            if(i==n-1) {
                if(freq[el]==el) {
                    continue;
                } else {
                    // left block
                    grid[i][j-1] = el;
                    freq[el]++;
                }
            } else if(j==0) {
                if(freq[el]==el) {
                    continue;
                } else {
                    // down block
                    grid[i+1][j] = el;
                    freq[el]++;
                }
            } else {
                if(freq[el]==el) {
                    continue;
                }
                if(grid[i+1][j]==0) {
                    grid[i+1][j] = el;
                    freq[el]++;
                } else {
                    grid[i][j-1] = el;
                    freq[el]++;
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}   
int32_t main()
{
    FIO;
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();    
    }
}
