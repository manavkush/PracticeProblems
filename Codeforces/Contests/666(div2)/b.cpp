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
vi a;
int n;

double nthRoot(int A, int N) 
{ 
    // intially guessing a random number between 
    // 0 and 9 
    double xPre = rand() % 10; 
  
    //  smaller eps, denotes more accuracy 
    double eps = 1e-3; 
  
    // initializing difference between two 
    // roots by INT_MAX 
    double delX = INT_MAX; 
  
    //  xK denotes current value of x 
    double xK; 
  
    //  loop untill we reach desired accuracy 
    while (delX > eps) 
    { 
        //  calculating current value from previous 
        // value by newton's method 
        xK = ((N - 1.0) * xPre + 
              (double)A/pow(xPre, N-1)) / (double)N; 
        delX = abs(xK - xPre); 
        xPre = xK; 
    } 
  
    return xK; 
} 

int solve(int x)
{
    int sum=0;
    re(i,n)
    {
        sum+=abs(pow(x,i)-a[i]);
    }
    return sum;
}

int32_t main()
{
    FIO;
    cin>>n;
    a.resize(n);
    re(i,n)
    {
        cin>>a[i];
    }
    vi b=a;
    sort(all(a));
    int l=0;
    int r=ceil(nthRoot((1e9),(n-1)))+10;
    // int low=min(solve(l),solve(r));
    while(l+1<r)
    {
        // cout<<l<<" "<<r<<" ";
        int mid=(l+r)/2;    
        if(solve(mid)>=solve(mid+1))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
        // cout<<solve(mid)<<" "<<solve(mid+1)<<endl;
    }
    
    cout<<solve(r)<<endl;
    
    
}