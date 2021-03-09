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
    string a,b;
    cin>>a>>b;
    int n1,n2;
    n1=a.length();
    n2=b.length();
    if(n1<n2) {
        swap(a,b);
        n1=a.length();
        n2=b.length();
    }
    int lcm = n1*n2/__gcd(n1,n2);
    string a1,b1;
    re(i,lcm/n1) {
        a1+=a;
    }
    re(i,lcm/n2) {
        b1+=b;
    }
    if(a1==b1) {
        cout<<a1<<endl;
    } else {
        cout<<-1<<endl;
    }

    // int ca,cb;
    // bool dbl=0;
    // re(i,n1-1) {
    //     if(a[i]!=a[i+1]) {
    //         dbl=1;
    //         break;
    //     }
    // }
    // bool dbl2=0;
    // re(i,n2-1) {
    //     if(b[i]!=b[i+1]) {
    //         dbl2=1;
    //         break;
    //     }
    // }
    // // debug(dbl, dbl2);
    // if((!dbl) and (!dbl2)) {
    //     // Both single char.
    //     if(a[0]==b[0]) {
    //         int times = (n1*n2)/__gcd(n1,n2);
    //         re(i,times) {
    //             cout<<a[0];
    //         }
    //         cout<<endl;
    //         return;
    //     } else {
    //         cout<<-1<<endl;
    //         return;
    //     }
    // } else if(dbl and dbl2) {
    //     if(n1%n2!=0) {
    //         cout<<-1<<endl;
    //         return;
    //     }
    //     re(i,n1) {
    //         re(j,n2) {
    //             if(a[i+j]!=b[j]) {
    //                 cout<<-1<<endl;
    //                 return;
    //             }
    //         }
    //         i+=n2-1;
    //     }
        
    //     re(i,n1/n2) {
    //         cout<<b;
    //     }
    //     cout<<endl;
    // } else {
    //     cout<<-1<<endl;
    //     return;
    // }

    
    
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