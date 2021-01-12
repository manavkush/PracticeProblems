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
int n;
vector<int> adj[27];
// void dfs(int i,vector<int> &vis) {
//         vis[i]=1;
//         for(auto x:adj[i]) {
//             if(!vis[x])
//             {
//                 vis[x]=1;
//                 dfs(x,vis);
//             }
//         }
//         cout<<char(i+'a');
// }

int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n=s.length();
        string ans;
        int curr=0;
        map<int,int> hash;
        vector<int> vis(27,0);
        int prev=-1;
        bool flag=1;
        for(int i=0;i<n;i++) {
            int letter=s[i]-'a';
            if(hash.count(letter)==0) {
                if(curr==ans.length()-1) {
                    ans+=s[i];
                    curr++;
                } else if(curr==0) {
                    ans = s[i]+ans;
                } else {
                    flag=0;
                    break;
                }
                hash[letter]=1;
            } else {
                if(curr==ans.length()-1) {
                    if(ans[curr-1]==s[i]) {
                        curr--;
                    } else {
                        flag=0;
                        break;
                    }
                } else if(curr==0) {
                    if(ans[1]==s[i]) {
                        curr++;
                    } else {
                        flag=0;
                        break;
                    }
                } else {
                    if(ans[curr+1]==s[i]) {
                        curr++;
                    } else if(ans[curr-1]==s[i]) {
                        curr--;
                    } else {
                        flag=0;
                        break;
                    }
                }
            }
        }
        if(flag) {
            cout<<"YES\n";
            for(int i=0;i<26;i++) {
                if(hash.count(i)) {
                    continue;
                } else {
                    ans+=char('a'+i);
                }
            }
            cout<<ans<<endl;
        } else {
            cout<<"NO\n";
        }

        re(i,27) {
            adj[i].clear();
        }
    }
}