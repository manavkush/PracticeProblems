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
set<int> wrong = {3,4,6,7,9};
bool check(int s) {
    while(s) {
        if(wrong.find(s%10)!=wrong.end()) {
            return false;
        }
        s/=10;
    }
    return true;
}
map<int,int> mirror;

int rev(int a) {
    int b = 0;
    
    while(a) {

    }
}

bool solveutility(int hr, int mn, int h, int m, int a, int b, map<int,pii> &mappper) {
    int new_min = 
}

void solve() {
    int h,m;
    cin>>h>>m;
    string start;
    cin>>start;
    
    map<int,pii> mapper;

    int a = stoi(start.substr(0,2));
    int b = stoi(start.substr(3,2));

    // debug(a,b);
    for(int hr=0;hr<h;hr++) {
        if(!check(hr)) {
            continue;
        }
        for(int mn=0;mn<m;mn++) {
            if(!check(mn)) {
                continue;
            }
            
            int dist=0;
            
            if(hr>a) {
                dist+=abs(m-b)*h;
                dist+=(hr-a-1);
                dist+=mn;
                dist+=(h-hr);

            } else if(hr<a) {
                dist+=(m-mn)*h;
                dist+=(a-hr-1);
                dist+=b;
            } else {
                dist+=abs(mn-b);
            }
            int dist2 = 0;
            dist2+=abs(m-mn);
            dist2+=abs(h-hr-1)*m;
            dist2+=abs(a*m);
            dist2+=b;
            mapper[dist2] = {hr, mn};
            mapper[dist] = {hr,mn};
        }
    }
    // debug(mapper);
    auto itr = mapper.begin();
    debug(itr->second);
}
int32_t main()
{
    FIO;
    mirror[0] = 0;
    mirror[1] = 1;
    mirror[2] = 5;
    mirror[5] = 2;
    mirror[8] = 8;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}