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

int nc3(int k) {
    return k*(k-1)*(k-2)/6;
}

int nc2(int k) {
    return k*(k-1)/2;
}

void solve() {
    int n;  // no of req nodes
    cin>>n;
    int matrix[105][105];
    int req = 0;
    for(int i=3;i<=100;i++) {
        if(nc3(i)<=n) {
            req = i;
        }
    }
    for(int i=0;i<req;i++) {
        for(int j=0;j<req;j++) {
            if(i!=j) {
                matrix[i][j] = 1;
            }
        }
    }

    n -= nc3(req);

    while(n) {
        // Adding a new node and trying to connect it to as many prev nodes as possible
        int high = 0;   // Storing the max nodes it can be connected
        for(int i=2; i<req;i++) {
            if(nc2(i) <= n) {
                high = i;
            }
        }
        n -= nc2(high);
        req++;
        // Updating the matrix
        for(int i=0;i<high;i++) {
            matrix[i][req-1] = 1;
            matrix[req-1][i] = 1;
        }
    }
    cout<<req<<endl;
    for(int i=0;i<req; i++) {
        for(int j=0;j<req;j++) {
            cout<<matrix[i][j];
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
