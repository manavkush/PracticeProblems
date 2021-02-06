// Author: manavkush
// Date: 17/12/2020

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

void solve() {
    int n,x;
    cin>>n>>x;
    vi a(n);
    re(i,n) {
        cin>>a[i];
    }
    if(is_sorted(all(a))) {
        cout<<0<<endl;
        return;
    }
    vi lows(n);
    bool flag = 1;
    re(i,n) {
        int count = 0;
        re(j,i) {
            if(a[i]<a[j]) {
                count++;
            }
        }
        lows[i] = count;
        if(count>1) {
            flag = 0;
            break;
        }
    }
    if(flag==0) {
        cout<<-1<<endl;
        return;
    }
    int curr = 0;   // index of element just greater than x;
    re(i,n) {
        if(a[i]>x) {
            curr = i;
            break;
        }
    }
    int count = 0;
    for(int i=0;i<n-1;i++) {
        if(i==0) {
            if(a[i]>a[i+1]) {
                if(x<=a[i+1]) {
                    count++;
                    swap(x,a[i]);
                } else {
                    flag = 0;
                    break;
                }
            }
        } else {
            if(a[i]>a[i+1]) {
                if(x>=a[i-1] and x<=a[i+1]) {
                    count++;
                    swap(a[i],x);
                } else if(x<a[i-1]) {
                    for(int k=curr; k<=i; k++) {
                        if(a[k]>x) {
                            swap(x,a[k]);
                            count++;
                        }
                    }
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }
    }
    if(flag==0) {
        cout<<-1<<endl;
    } else {
        cout<<count<<endl;
    }


}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}
