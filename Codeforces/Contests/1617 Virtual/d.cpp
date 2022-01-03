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
// #define endl "\n"
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
int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        int n, imp, crew;
        cin>>n;
        vector<int> a(n, -1);
        set<int> s;
        int prev, curr;
        cout<<"? 1 2 3"<<endl;
        cin>>curr;
        prev = curr;
        for(int i=2;i<=n-2;i++) {
            cout<<"? "<<i<<" "<<i+1<<" "<<i+2<<endl;
            cin>>curr;
            if(curr!=prev) {
                if(curr == 1) {
                    imp = i-1;
                    crew = i+2;
                    s.insert(i-1);
                    break;
                } else {
                    imp = i +2;
                    crew = i-1;
                    s.insert(imp);
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(i==crew || i==imp) {
                continue;
            } else {
                cout<<"? "<<imp<<" "<<crew<<" "<<i<<endl;
                cin>>curr;
                if(curr == 1) {
                    continue;
                } else {
                    s.insert(i);
                }
            }
        }
        cout<<"! "<<s.size()<<" ";
        for(auto x: s) {
            cout<<x<<" ";
        }
        cout.flush();


    }
}