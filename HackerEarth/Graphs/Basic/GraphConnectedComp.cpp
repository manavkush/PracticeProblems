#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

const int N = 1e6;
vector<int> adj[N];
bool visited[N]={0};

void dfs(int s)
{
    visited[s]=true;
    for(auto x:adj[s])
    { 
        if(!visited[x])
            dfs(x);
    }
}
int main()
{
    FIO;
    int a,b,m,n;
    cin>>n>>m;
    re(i,m)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cc=0;
    re1(i,1,n)
    {
        if(!visited[i])
        {   
            dfs(i);
            cc++;
        }
    }
    cout<<cc;

}