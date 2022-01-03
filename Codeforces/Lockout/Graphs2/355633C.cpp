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
    int n,k;
    cin>>n>>k;
    vi d(n);
    re(i,n) {
        cin>>d[i];
    }
    bool flag = 0;
    vi freq(n, 0);
    re(i,n) {
        freq[d[i]]++;
    }
    if(freq[0]>1) {
        flag = 1;
    }
    for(int i=1; i<n; i++) {
        if(i==1) {
            if(freq[i] > freq[i-1]*k) {
                flag = 1;
                break;
            }
        } else {
            if(freq[i]>freq[i-1]*(k-1)) {
                flag = 1;
                break;
            }
        }
    }
    
    if(flag) {
        cout<<-1<<endl;
        return;
    }
    vector<vector<int>> hash(n);    // distance, node
    for(int i=0;i<n;i++) {
        hash[d[i]].push_back(i);
    }
    for(auto x: hash) {
        debug(x);
    }
    vector<pair<int,int>> edgelist;
    
    // iterates the distance hash
    for(int i=1;i<n;i++) {
        int idx = 0;  // Stores the idx of the element to be processed
        int cnt;  // counts the number of neighbours
        if(i==1) cnt = 0;
        else cnt = 1;
        bool done=0;
        for(int j=0;j<hash[i-1].size() and (!done);j++) {   // j iterates the first
            for(int l=idx;l<hash[i].size();l++) {  
                // l iterates the next 
                edgelist.pb({hash[i-1][j], hash[i][l]});
                idx++; cnt++;

                // Second list over
                if(l>=hash[i].size()) {
                    done = 1;
                    break;
                }
                // k edges over
                if(cnt >= k) {
                    cnt = 1;
                    break;
                }
            }
        }
    }
    cout<<edgelist.size()<<endl;
    for(auto x: edgelist) {
        cout<<x.ff+1<<" "<<x.ss+1<<endl;
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
