#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define pb push_back
#define fast() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define input \
    ll t;     \
    cin >> t; \
    while (t--)
typedef long long ll;

int n;

int dfs(vector<int> adj[], int source, bool visited[])
{
    stack<int> s;
    int i, p, count = 0;
    // bool visited[n+1]={false};
    s.push(source);
    visited[source] = true;
    while (!s.empty())
    {
        p = s.top();
        s.pop();
        for (i = 0; i < adj[p].size(); ++i)
        {
            if (visited[adj[p][i]] == false)
            {
                visited[adj[p][i]] = true;
                s.push(adj[p][i]);
                if (p == 1)
                {
                    if ((adj[adj[p][i]].size() - 1) > adj[p].size())
                        count++;
                }
                else if (adj[adj[p][i]].size() > adj[p].size())
                    count++;
            }
        }
    }
    return count;
}

int main(void)
{
    int m, i, x, y, count = 0;
    cin >> n >> m;
    vector<int> adj[n + 1];
    bool visited[n + 1] = {false};
    for (i = 0; i < m; ++i)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (i = 1; i <= n; ++i)
    {
        if (visited[i] == false)
            count += dfs(adj, i, visited);
    }
    cout << count << endl;
    return 0;
}