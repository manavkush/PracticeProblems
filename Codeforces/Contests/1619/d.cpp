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
    int m,n;
    cin>>m>>n;

    vector<vector<int>> mat(m, vector<int> (n));
    re(i,m) {
        re(j,n) {
            cin>>mat[i][j];
        }
    }
    vector<int> col_maxes(n);   // stores the indexes of rows
    re(i,n) {
        int mx = 0;
        re(j,m) {
            if(mat[j][i] > mat[mx][i]) {
                mx = j;
            }
        }
        col_maxes[i] = mx;
    }
    map<int,int> hash;
    for(auto &x: col_maxes) {
        hash[x]++;
    }
    if(hash.size()<n) {
        // cout<<"**";
        hash.clear();
        int low = INT_MAX;
        for(int i=0;i<n;i++) {
            int el = mat[col_maxes[i]][i];
            if(el<low) {
                low = el;
            }
        }
        cout<<low<<endl;
        return;
    } else {
        // cout<<"*****";
        int high = 0;
        for(int i=0;i<m;i++) {
            int first, second;
            first = second = 0;
            for(int j=0;j<n;j++) {
                if(mat[i][j]>=first) {
                    second = first;
                    first = mat[i][j];
                } else if(mat[i][j]>second) {
                    second = mat[i][j];
                }
            }
            // debug(high, second);
            high = max(high, second);
        }
        cout<< high <<endl;
        return;
    }
}
int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}