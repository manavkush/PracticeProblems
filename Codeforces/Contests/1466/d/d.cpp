// Author: manavkush
// Date: 30/12/2020

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
vi weights;

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        weights.resize(n+1);
        vector<int> adj[n+1];   // Adjacency list
        vi deg(n+1); // stores the degree
        int u,v;
        maxpq pq;   // Weights,index
        
        int sum=0;
        re(i,n) {
            cin>>weights[i+1];
            sum+=weights[i+1];
            pq.push({weights[i+1],i+1});    
        }
        re(i,n-1) {
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cout<<sum<<" ";
        for(int i=1;i<n-1;i++) {
            while(1) {
                if(pq.empty()) {
                    break;
                }
                auto x = pq.top();
                pq.pop();   // Pop of the top element

                if(deg[x.ss]>1) {
                    sum+=x.ff;
                    deg[x.ss]--;
                    if(deg[x.ss]>1) {   // If more edges present
                        pq.push({weights[x.ss],x.ss});
                    }
                    break;
                }
            }
            cout<<sum<<" ";
        }
        cout<<endl;

    }
}
