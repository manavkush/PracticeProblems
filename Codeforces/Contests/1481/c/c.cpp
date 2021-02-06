// Author: manavkush
// Date: 05/02/2021

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
    int n,m;
    cin>>n>>m;
    vi a(n),b(n),c(m);
    vi avail(n+1), req(n+1);
    vi total(n+1);
    vi last(n+1);
    vector<vector<int>> positions(n+1); // Color -> Positions
    vector<int> ans(m,-1);
    

    re(i,n) {
        cin>>a[i];  // Initial Colors of fence
    }
    re(i,n) {
        cin>>b[i];  // Final Colors of fence
        if(a[i]!=b[i]) {
            req[b[i]]++;
            positions[b[i]].pb(i);
        }
        total[b[i]]++;
        last[b[i]]=i;   // Stores the last occuracnce of each
    }
    re(i,m) {
        cin>>c[i];  // colors painters have
        avail[c[i]]++;
    }
    bool okay = 1;
    re1(i,1,n) {
        if(avail[i]<req[i]) {
            okay = 0;
            break;
        }
    }
    if(!okay) {
        cout<<"NO\n";
        return;
    }
    if(total[c[m-1]]==0) {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    // if(positions[c[m-1]].empty())
    // int lastel = positions[c[m-1]][0];
    int wrong;
    if(req[c[m-1]]==0) {    // If there is no requirement of last paint
        wrong = last[c[m-1]];
    } else {
        wrong = positions[c[m-1]][0];
    }

    re(i,m) {
        if(req[c[i]]==0) {
            ans[i] = wrong;
        } else {
            ans[i] = positions[c[i]].back();
            positions[c[i]].pop_back();
            req[c[i]]--;
        }
    }
    for(auto x: ans) {
        cout<<x+1<<" ";
    }
    cout<<endl;

}

int32_t main()
{
    FIO;
    int t;cin>>t;
    while(t--)
    {
        solve();
        // int n,m;
        // cin>>n>>m;
        // vi a(n),b(n),c(m);
        // unordered_map<int,int> avail;
        // unordered_map<int,int> required;
        
        // unordered_map<int, set<int> > positions;    // Color-> Positions
        // vi ans(m,-1);
        
        // for(int i=1;i<=n;i++) {
        //     required[i]=0;
        //     avail[i]=0;
        // }
        
        // bool check = 1;
        
        // re(i,n) {
        //     if(required[i+1]>avail[i+1]) {
        //         check=0;
        //         break;
        //     }
        // }
        // // If less than required paints
        // if(check==0) {
        //     cout<<"NO\n";
        //     continue;
        // }
        // // If there is no requirement of the last paint
        // int pos = -1;
        // re(i,n) {
        //     if(b[i]==c[m-1]) {
        //         pos = i;
        //         break;
        //     }
        // }
        // if(pos==-1) {
        //     cout<<"NO\n";
        //     continue;
        // }

        // cout<<"YES\n";
        // int last = pos;
        // re(i,m) {
        //     if(required[c[i]]==0) {
        //         continue;
        //     } else {
        //         auto val = positions[c[i]].begin();
        //         required[c[i]]--;
        //         ans[i] = *val;
        //         positions[c[i]].erase(val);
        //     }
        // }
        // // for(int i=1;i<=n;i++) {
        // //     int count=0;
        // //     int high=required[i];
        // //     auto itr = positions[i]
        // //     while(count<high) {

        // //     }
        // // }


        // re(i,m) {
        //     if(ans[i]==-1) {
        //         ans[i] = pos;
        //     }
        // }
        // for(auto x: ans) {
        //     cout<<x+1<<" ";
        // }
        // cout<<endl;

    }
}
