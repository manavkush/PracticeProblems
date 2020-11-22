#include <bits/stdc++.h>

#include <fstream>
#include <iomanip>
using namespace std;

int n, m;
vector<pair<int, int>> *adj;
vector<pair<int, int>> sf(10);

void dfsHelper(int src, bool vis[], int &start) {
    sf[src].first = start;
    start++;
    vis[src] = true;
    for (auto nbr : adj[src]) {
        int id = nbr.first;
        if (!vis[id]) {
            dfsHelper(id, vis, start);
        } else {
        }
    }
    sf[src].second = start;
    start++;
}
void dfs() {
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    int start = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfsHelper(i, vis, start);
        }
    }
}
int main(int argc, char **arg) {
    //Declaring streams
    ifstream fin;
    ofstream fout;

    fin.open(arg[1]);
    fout.open("190010034-1.txt");

    //taking input and making adj list
    cin >> n >> m;
    adj = new vector<pair<int, int>>[n + 1];

    //taking input of edges

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs();
    cout << "------------" << endl;
    int i = 0;
    for (int i = 0; i < n; i++) {
        cout << i << " " << sf[i].first << " " << sf[i].second << endl;
    }

    fin.close();
    fout.close();
    return 0;
}