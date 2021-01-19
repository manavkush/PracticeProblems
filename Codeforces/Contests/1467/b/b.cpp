// Author: manavkush
// Date: 08/01/2021

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


int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n);
        re(i,n) {
            cin>>a[i];
        }
        if(n<3) {
            cout<<0<<endl;
            continue;
        } else {
            // Base conditions
            if(is_sorted(all(a))) {
                cout<<0<<endl;
                continue;
            } 
            vi b=a;
            sort(all(b),greater<int>());
            if(b==a) {
                cout<<0<<endl;
                continue;
            }
            string str(n,'*');
            b.clear();
            b.resize(n,0);
            int flag=0;

            int count=0;
            re1(i,1,n-2) {
                if(a[i]>a[i-1]&& a[i]>a[i+1]) {
                    b[i]=1;
                    str[i]='a';
                    count++;
                } else if( a[i]<a[i-1] && a[i]<a[i+1]) {
                    b[i]=-1;
                    str[i]='b';
                    count++;
                }
            }
            debug(str);
            int ans=0;
            if((str.find("aba")!=string::npos)||(str.find("bab")!=string::npos))
            ans=3;
            else if((str.find("ab")!=string::npos)||(str.find("ba")!=string::npos))
            ans = 2;
            else {
                ans=1;
            }

            cout<<count-ans<<endl;
            // if(b.find())
        }
    }
}
