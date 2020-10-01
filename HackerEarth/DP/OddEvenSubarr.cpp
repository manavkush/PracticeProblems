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

// You are given an array A of N positive integer values. A subarray of this array is called Odd-Even subarray if the number of odd integers in this subarray is equal to the number  of even integers in this subarray.

// Find the number of Odd-Even subarrays for the given array.

int main()
{
    FIO;
    int n;
    cin>>n;
    vi a(n+1);
    vi odd(n+1);
    vi even(n+1);
    re1(i,1,n+1)
    {
        cin>>a[i];
        if(a[i]&1)
        {
            odd[i]=odd[i-1]+1;
            even[i]=even[i-1];
        }
        else
        {
            odd[i]=odd[i-1];
            even[i]=even[i-1]+1;
        }
    }
    lli sum=0;
    // for(int i=2;i<=n;i++)
    // {
    //     for(int j=0;j<i;j++)
    //     {
    //         if(odd[i]-odd[j]==even[i]-even[j])
    //             sum++;
    //     }
    // }
    vi dif(n+1);
    for(int i=0;i<=n;i++)
    {
        dif[i]=odd[i]-even[i];
    }
    map<int,int> m;
    for(int i=0;i<=n;i++)
    {
        m[dif[i]]++;
    }
    tr(itr,m)
    {
        int val=itr->second;
        sum+=(val*(val-1))/2;
    }
    cout<<sum;

}