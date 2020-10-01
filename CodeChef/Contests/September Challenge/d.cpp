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
int factorial(int n) 
{ 
    // single line to find factorial 
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); 
} 

int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if(n<=2)
        {
            cout<<0<<endl;
            continue;
        }
        if(n==3)
        {
            cout<<2<<endl;
            continue;
        }
        if(n%4!=0&&(n+1)%4!=0)
        {
            cout<<0<<endl;
            continue;
        }

        int tot=n*(n+1)/4;      // This is the sum of f elements
        int f=floor(sqrt(tot));
        // cout<<f<<" ";
        
        // Calculating the number of elements to be choosen for sum.
        while(f*f+f<=2*tot)  {
            f++;
        }

        if(f*f+f>2*tot)  {
            f--;
            // cout<<f<<"\t";
        }
        //===============================
        cout<<f<<"\t";
        if(f*f+f<2*tot)
        {
            int dif=tot-(f*f+f)/2;
            int count=0;
            int ptr=n;
            deb(dif);
            while(ptr-dif>0&&ptr>f)
            {
                if(ptr-dif>f)
                {
                    ptr--;
                    continue;
                }
                cout<<ptr<<" ";
                ptr--;
                count++;
            }
            cout<<"\t";
            cout<<count<<endl;
            continue;
        }
        else if(f*f+f==2*tot)
        {
            cout<<f*(f-1)/2+(n-f)*(n-f-1)/2+1<<endl;
            continue;
        }
        cout<<n-f<<endl;

    }
    
}