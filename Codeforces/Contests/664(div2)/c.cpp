#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int lli;
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
#define re1(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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


int main()
{
    FIO;
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    re(i,n)
    {
        cin>>a[i];
    }
    re(i,m)
    {
        cin>>b[i];
    }
    vi ans[n];
    re(i,n)
    {
        re(j,m)
        {
            ans[i].pb(a[i]&b[j]);
        }
    }
    lli sum=0;
    int z=0;
    // cout<<endl;
    // re(i,n)
    // {
    //     re(j,m)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    while(1)
    {
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            // cout<<"* ";
            bool check=0;
            for(int j=0;j<m;j++)
            {
                if((ans[i][j]|z)==z)
                {
                    // cout<<ans[i][j]<<" "<<z<<" "
                    check=1;
                    break;
                }
            }
            if(check)
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag)
            z++;
        else
        {
            cout<<z;
            return 0;
        }
    }
}