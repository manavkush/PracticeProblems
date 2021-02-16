// Author: manavkush
// Date: 14/02/2021

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
bool comp(pii &a, pii &b) {
    if(a.ff!=b.ff) {
        return a.ff<b.ff;
    } else {
        return a.ss>b.ss;
    }
}

int indv(int x, int y, int n) {
    return max(abs(x),abs(n-x-1))*max(abs(y),abs(n-y-1));
}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[n][n];
        vector<pii> a[10];
        re(i,n) {
            re(j,n) {
                char val;
                cin>>val;
                mat[i][j]=val-'0';
            }
        }
        vector<int> maxc(10,-1);
        vector<int> maxr(10,-1);
        vector<int> minc(10,INT_MAX);
        vector<int> minr(10,INT_MAX);
        // int maxc[10]={-1};
        // int maxr[10]={-1};
        // int minc[10]={INT_MAX};
        // int minr[10]={INT_MAX};

        re(i,n) {
            re(j,n) {
                int dig= mat[i][j];
                maxc[dig]=max(maxc[dig],j);
                minc[dig]=min(minc[dig],j);
                maxr[dig]=max(maxr[dig],i);
                minr[dig]=min(minr[dig],i);                
            }
        }
        // re(i,10) {
        //     debug(i,maxc[i],maxr[i],minc[i], minr[i]);
        // }
        vi res(10,0);
        re(i,n) {
            re(j,n) {
                int val = mat[i][j];
                int a1 = max(abs(maxr[val]-i),abs(minr[val]-i))*max(abs(n-j-1),abs(j));
                int a2 = max(abs(maxc[val]-j),abs(minc[val]-j))*max(abs(n-i-1),abs(i));
                int area = max(a1,a2);
                res[val] = max(res[val],area);
            }
        }

        for(auto x: res) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
