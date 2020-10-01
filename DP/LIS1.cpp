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

// This question is a very good question which taught me about longest increasing subsequence

// The function below takes a vector and and integer as the input and then
// returns the length of the longest increasing subsequence
// We start by making a vector which whose size will give us the answer
// Each index of the ans vector stores the last element of a subsequence of length of that index
// We use lower_bound function.
// lower bound acts as a binary search when the vector is sorted which the ans vector is.
// We replace the element just bigger than that of the current element by current element


int lis(vi v,int n)
{
    vi ans;
    ans.pb(v[0]);
    for(int i=1;i<n;i++)
    {
        if(v[i]>ans.back())
        {
            ans.pb(v[i]);
        }
        else
        {
            int length=lower_bound(ans.begin(),ans.end(),v[i])-ans.begin();
            ans[length]=v[i];
        }
    }
    //deb(ans.size());
    return ans.size();
}

int main()
{
    FIO;
    int n;
    cin>>n;
    vi v(n);
    re(i,n)
    {
        cin>>v[i];
    }
    int inc=lis(v,n);
    reverse(all(v));
    //__print(v);
    int dec=lis(v,n);
    cout<<n-max(inc,dec);
}