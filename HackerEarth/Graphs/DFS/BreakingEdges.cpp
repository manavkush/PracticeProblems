// This was a very good problem and editorial was needed to solve it
// We first take the values of the various nodes and convert them to binary
// We then start a dfs from the source and then make a sum of all the subnodes's bits for each node
// We then again start a dfs and for each edge check that either both the bits are 0 or both are above 1

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
const int N = 2e5 + 10;
vector<int> adj[N];
vector<bool> vis(N, 0);
vector<int> val(N);
int mat[N][22];
int cnt = 0;
void dfs(int s)
{
    vis[s] = 1;
    for (auto x : adj[s])
    {
        if (vis[x])
            continue;
        dfs(x);
        re(i, 22)
        {
            mat[s][i] += mat[x][i];
        }
    }
}
void dfsUtil(int s)
{
    vis[s] = 1;

    for (auto x : adj[s])
    {
        if (vis[x])
            continue;
        dfsUtil(x);
        int flag = 1;
        re(i, 22)
        {
            if (((mat[x][i] > 0) && (mat[1][i] - mat[x][i] > 0)) || ((mat[x][i] == 0) && (mat[1][i] == 0)))
                continue;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cnt++;
        }
    }
}

int main()
{
    FIO;
    int n;
    cin >> n;
    re1(i, 1, n)
    {
        cin >> val[i];
        int temp = val[i];
        int j = 0;
        while (temp)
        {
            int p = temp % 2;
            mat[i][j] = p;
            j++;
            temp /= 2;
        }
    }
    re(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    fill(vis.begin(), vis.end(), false); //Sets all the visited to false
    dfsUtil(1);

    cout << cnt;
}