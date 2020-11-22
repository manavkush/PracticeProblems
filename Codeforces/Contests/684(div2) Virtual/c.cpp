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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string str[n];
        int store[n][m];
        re(i,n)
        {
            cin>>str[i];
        }
        re(i,n)
        {
            re(j,m)
            {
                store[i][j]=str[i][j]-'0';
            }
        }
        vector<pii> ans;

        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(store[i][j]==0)
                    continue;
                else
                {
                    {
                        store[i][j]=!store[i][j];
                        store[i+1][j+1]=!store[i+1][j+1];
                        store[i+1][j]=!store[i+1][j];
                        ans.pb(mp(i,j));
                        ans.pb(mp(i+1,j+1));
                        ans.pb(mp(i+1,j));
                    }
                    
                }
            }
            if(store[i][m-1]==1)
            {
                store[i][m-1]=!store[i+1][m-1];
                store[i+1][m-1]=!store[i+1][m-1];
                store[i+1][m-2]=!store[i+1][m-2];         

                ans.pb(mp(i,m-1));
                ans.pb(mp(i+1,m-1));
                ans.pb(mp(i+1,m-2));            
            }
        }
        for(int i=0;i<m-1;i++)
        {
            if(store[n-1][i]==0)
                continue;
            else
            {
                store[n-1][i]=!store[n-1][i];   
                store[n-1][i+1]=!store[n-1][i+1];
                
                ans.pb(mp(n-2,i));
                ans.pb(mp(n-2,i+1));
                ans.pb(mp(n-1,i));

                ans.pb(mp(n-1,i+1));
                ans.pb(mp(n-2,i));
                ans.pb(mp(n-2,i+1));
            }
        }
        if(store[n-1][m-1]!=0)
        {
            ans.pb(mp(n-2,m-1));
            ans.pb(mp(n-2,m-2));
            ans.pb(mp(n-1,m-1));

            ans.pb(mp(n-2,m-1));
            ans.pb(mp(n-1,m-2));
            ans.pb(mp(n-1,m-1));

            ans.pb(mp(n-2,m-2));
            ans.pb(mp(n-1,m-2));
            ans.pb(mp(n-1,m-1));
        }
        cout<<ans.size()/3<<endl;
        for(int i=0;i<ans.size();i=i+3)
        {
            cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<" "<<ans[i+1].ff+1<<" "<<ans[i+1].ss+1<<" "<<ans[i+2].ff+1<<" "<<ans[i+2].ss+1<<endl;
        }
    }

}