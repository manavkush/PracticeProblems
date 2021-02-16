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
    string str;
    cin>>str;
    int f,s,t;
    bool flag = 1;
    re(i,str.size()) {
        if(str[i]=='0') {
            flag = 0;
            break;
        }
    }
    if(!flag) {
        cout<<"YES\n";
        cout<<0<<endl;
        return 0;
    }
    re(i,str.size()) {
        if(str[i]=='8') {
            flag = 0;
            break;
        }
    }
    if(!flag) {
        cout<<"YES\n";
        cout<<8<<endl;
        return 0;
    }
    if(str.size()<=3  ) {
        if(stoi(str)%8!=0) {
            cout<<"NO\n";
            return 0;
        } else {
            cout<<"YES\n";
            cout<<str<<endl;
            return 0;
        }
    }
    int n = str.size();
    for(int i=n-3;i>=0 and flag; i--) {
        for(int j=n-2;j>i and flag; j--) {
            for(int k=n-1;k>j and flag; k--) {
                string temp;
                temp+=(str[i]);
                temp+=(str[j]);
                temp+=(str[k]);
                int val = stoi(temp);
                if(val%8==0) {
                    cout<<"YES\n";
                    cout<<val<<endl;
                    flag = 0;
                }
            }
        }
    }
    if(flag) {
        cout<<"NO\n";
    }

}
