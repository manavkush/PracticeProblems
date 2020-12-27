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

// Getting the lcs length is very easy and I was able to do that.
// The main challenge was to get the string itself
// For that we made a choice array and stored the choice that each of the dp element choose
// We then traced back from n,m 


int32_t main()
{
    FIO;
    string s,t;
    cin>>s>>t;
    
    // debug(s,t);
    vector<vi> lcs(3001,vi(3001,0));
    vector<vi> choice(3001,vi(3001,0));

    // States--> lcs string
    int n,m;
    n=s.size();
    m=t.size();
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i-1]==t[j-1]) {    // If characters are equal
                lcs[i][j]=lcs[i-1][j-1]+1;
                choice[i][j]=2;
            }
            else if(lcs[i][j-1]<lcs[i-1][j]) {
                lcs[i][j]=lcs[i-1][j];
                choice[i][j]=1;
            } else {
                lcs[i][j]=lcs[i][j-1];
            }
        }
    }
    int i=n;
    int j=m;
    string subs;
    while(i>0&&j>0) {
        if(choice[i][j]==2) {
            subs.push_back(s[i-1]);
            i--;
            j--;
        } else if(choice[i][j]==1) {
            i--;
        } else {
            j--;
        }
    }
    reverse(all(subs));
    cout<<subs<<endl;
    // cout<<lcs[n][m]<<endl;
}
