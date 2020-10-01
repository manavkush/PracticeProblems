#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
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
#define re1(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N, 0);

int dfs(int s, int child)
{
    vis[s] = true;
    int ret = 0;
    for (auto x : adj[s])
    {
        if (vis[x])
            continue;

        vis[x] = true;
        if (child == 0)
            ret += dfs(x, adj[s].size());
        else
            ret += dfs(x, adj[s].size() - 1);
    }
    if (child == 0)
        return ret;
    if (adj[s].size() - 1 > child)
    {
        return ret + 1;
    }
    else
        return ret;
}

int main()
{
    FIO;
    int n, m;
    cin >> n >> m;
    re(i, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    re1(i, 1, n)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    lli sum = 0;
    re1(i, 1, n)
    {
        if (vis[i])
            continue;
        sum += dfs(i, 0);
    }
    cout << sum;
}