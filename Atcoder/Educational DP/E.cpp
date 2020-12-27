// This was a good twist question to the classical knapsack problem. I had gotten the approach 
// but wasn't sure of it. So I looked up the demoralizer's video.
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
const int mod = 1000000007;
//===================================DEBUG TEMPLATE=================================================
void __print(int x) {
    cerr << x;
}
void __print(float x) {
    cerr << x;
}
void __print(double x) {
    cerr << x;
}
void __print(long double x) {
    cerr << x;
}
void __print(char x) {
    cerr << '\'' << x << '\'';
}
void __print(const char* x) {
    cerr << '\"' << x << '\"';
}
void __print(const string& x) {
    cerr << '\"' << x << '\"';
}
void __print(bool x) {
    cerr << (x ? "true" : "false");
}

template <typename T, typename V>
void __print(const pair<T, V>& x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() {
    cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v) {
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
const int N = 1e5;

int32_t main() {
    FIO;
    int n, W;
    cin >> n >> W;
    vi w(n + 1), a(n + 1);
    re1(i, 1, n) {
        cin >> w[i] >> a[i];
    }
    vector<vi> dp(n + 1, vi(N + 1, INT_MAX));  
    // States --> Indices taken for choosing, Total value got
    // Stores the total weight formed
    // We stores the minimum weight that we can get when choosing from i indices that sum to value 'val'
    re1(i,0,n) {
        dp[i][0] = 0;
    }
    re1(i,1,n) {
        re1(val,1,N) {
            if(val<a[i]) {
                dp[i][val] = dp[i-1][val];
            }
            else {
                dp[i][val] = min(dp[i-1][val],dp[i-1][val-a[i]]+w[i]);
            }
        }
    }
    int answer = 0;
    re1(i,N,0) {
        if(dp[n][i]<=W) {
            answer=i;
            break;
        }
    }
    cout<<answer<<endl;
}