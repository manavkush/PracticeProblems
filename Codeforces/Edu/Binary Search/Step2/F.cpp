#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
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
vector<int> v;
string a, b;
int t, p;
bool solve(int m)
{
    string temp=a;
    string cpy="";
    re(i,m)
    {
        temp[v[i]]='*';
    }
    re(i,t)
    {

        if(temp[i]!='*')
        {
            cpy+=temp[i];
        }
    }
    // cout<<temp<<" "<<cpy<<" "<<b<<endl;
    // cpy is a string created by deleting all the elements of string a from 0 to m
    int sz=cpy.size();
    int j=0;    // index of b;
    for(int i=0;i<sz&&j<p;i++)
    {
        if(cpy[i]==b[j]) {
            j++;
        }
    }

    return (j==p);
    
}

int32_t main()
{
    FIO;
    cin >> a >> b;
    t = a.size(), p = b.size();
    // cout<<t<<" "<<p<<endl;
    v.resize(t);
    re(i,t)
    {
        cin>>v[i];
        v[i]--;
    }
    int l=0; // This is always true ie string b can be formed when l characters are deleted
    int r=t; // This is always false ie string b cannot be formed when r characters are deleted
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(solve(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
        // cout<<l<<" "<<r<<endl;
    }
    cout<<l<<endl;
}