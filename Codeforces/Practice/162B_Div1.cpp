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
const int N=1e5+4;
//====================================DEBUG TEMPLATE==============================================

vi a(N);         // Storing the input
vi dp(N,0);
map<int,int> m[N];      // Map to store the prime factors of each no from 1 to 1e5


//============================================Pre-calculation====================================
int spf[N];     // Smallest prime factor of every number

void seive()    // One time smallest prime factor calculation ( Pre-pre computation)
{
    for(int i=1;i<N;i++) {
        spf[i] = i;
    }
    for(int i=2;i<N;i=i+2) {
        spf[i] = 2;
    }
    for(int i=3;i*i<N;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i;j<N;j+=i)       // Iterating over the multiples of i
            {
                if(spf[j]==j)     // If the element j reached from i hasn't been reached before then the spf of j is i
                    spf[j]=i;
            }
        }
    }
}
//=============================================Pre-calculation done ===============================

int32_t main()
{
    FIO;
    int n;
    cin>>n;
    re(i,n)
    {
        cin>>a[i];
    }
    if(n==1&&a[0]==1)
    {
        cout<<1;
        return 0;
    }
    seive();
    // This is precomputation of factors of all integers from 1 to 1e5
    for(int i=2;i<N;i++)
    {
        int num=i;
        while(num!=1)
        {
            m[i][spf[num]]++;
            num/=spf[num];   
        }
    }
    // Now we have the Prime factorization of all the numbers from 2 to N
    
    
    for(int i=0;i<n;i++)
    {
        int number = a[i];
        tr(itr,m[number])       // updating the number
        {
            int factor = itr->first;
            dp[number] = max(dp[number],dp[factor]+1);
        }
        
        tr(itr,m[number])       // updating the factors 
        {
            dp[itr->first] = dp[number];
        }
    }
    
    cout<<*max_element(all(dp));

}