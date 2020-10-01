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
    int n,m;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<"48 50\n";
    map<int, char> mp;
    mp[1]='A';
    mp[2]='B';
    mp[3]='C';
    mp[4]='D';
    a--;b--;c--;d--;
    int mat[48][50];
    re(i,12)        // Block 1
    {

        for(int j=0;j<50;j++) 
        {
            if(i==0)
            {
                re(j,50)
                {
                    mat[i][j]=1;
                }
                continue;
            }
            if((!(j&1))&&b&&(!(i&1))) {
                mat[i][j]=2;
                b--;
            }
            else  {
                mat[i][j]=1;
            }
        }
    }
    
    re1(i,12,23)        // Block 2
    {
        for(int j=0;j<50;j++) 
        {
            if(i==12)
            {
                re(j,50)
                {
                    mat[i][j]=2;
                }
                continue;
            }
            if((!(j&1))&&a&&(!(i&1))) 
            {
                mat[i][j]=1;
                a--;
            }
            else  
            {
                mat[i][j]=2;
            }
        }
    }
    
    re1(i,24,35)        // Block 3
    {
        for(int j=0;j<50;j++) 
        {
            if(i==24)
            {
                re(j,50)
                {
                    mat[i][j]=3;
                }
                continue;
            }
            if((!(j&1))&&d&&(!(i&1))) 
            {
                mat[i][j]=4;
                d--;
            }
            else  
            {
                mat[i][j]=3;
            }
        }
    }
    re1(i,36,47)        // Block 4
    {
        if(i==36)
        {
            re(j,50)
            {
                mat[i][j]=4;
            }
            continue;
        }
        for(int j=0;j<50;j++) 
        {

                if((!(j&1))&&c&&(!(i&1))) {
                    mat[i][j]=3;
                    c--;
                }
                else  {
                    mat[i][j]=4;
                }
        }
    }
    re(i,48)
    {
        re(j,50)
        {
            cout<<mp[mat[i][j]];
        }
        cout<<endl;
    }

}