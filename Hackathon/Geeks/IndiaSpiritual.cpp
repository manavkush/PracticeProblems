// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxCities(vector<vector<char>> &a, int n, int m);

// Driver code to test above functions
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> a(n, vector<char>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        cout << maxCities(a, n, m) << "\n";
    }

    return 0;
} // } Driver Code Ends

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
bool isvalid(int row, int col, int n, int m, vector<vector<bool>> &vis, vector<vector<bool>> &mat)
{
    if (row < 0 || row >= n)
        return false;
    if (col < 0 || col >= m)
        return false;
    if (vis[row][col])
        return false;
    if (mat[row][col] == 0)
        return false;
    return true;
}

int bfs(int row, int col, int n, int m, vector<vector<bool>> &vis, vector<vector<bool>> &mat)
{
    queue<int> qr, qc;
    qr.push(row);
    qc.push(col);
    vis[row][col] = 1;
    // *(vis+row*m+col)=1;
    int count = 0;
    while (!qr.empty())
    {
        int x, y;
        x = qr.front();
        y = qc.front();
        count++;
        qr.pop(), qc.pop();
        for (int i = 0; i < n; i++)
        {
            int rr = x + dr[i];
            int cc = y + dc[i];
            if (isvalid(rr, cc, n, m, vis, mat))
            {
                // *(vis+rr*m+cc)=1;
                vis[rr][cc] = 1;
                qr.push(rr);
                qc.push(cc);
            }
        }
    }
    return count;
}
int maxCities(vector<vector<char>> &a, int n, int m)
{
    vector<vector<bool>> mat(n, vector<bool>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    // bool mat[n][m],vis[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = 0;
            vis[i][j] = 0;
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
            {
                for (int r = 0; r < 8; r++)
                {
                    int rr = i + dr[r];
                    int cc = j + dc[r];
                    if (rr < 0 || rr >= n)
                        continue;
                    if (cc < 0 || cc >= m)
                        continue;
                    if (a[rr][cc] == '*')
                        continue;
                    mat[rr][cc] = 1;
                }
            }
        }
    }
    int ans = 0;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<(mat[i][j]?1:0);
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] || mat[i][j] == 0)
                continue;
            ans = max(ans, bfs(i, j, n, m, vis, mat));
        }
    }
    return ans;
}