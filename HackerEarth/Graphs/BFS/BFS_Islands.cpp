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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int bfs(int s,int n,bool vis[],vector<int> adj[])
{
    queue<int> q;
    q.push(s);
    vis[s]=true;
    int currlayer=1;
    int nextlayer=0;
    int movecount=0;
    while (!q.empty())
    {
        int top=q.front();
        q.pop();
        currlayer--;

        //deb(top);
        if(top==n)
            return movecount;
        for(auto x:adj[top])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=true;
                nextlayer++;
            }
        }
        if(currlayer==0)
        {
            movecount++;
            currlayer=nextlayer;
            nextlayer=0;
        }
    }
    return -1;
    
}

int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,m;
        cin>>n>>m;
        vector<int> adj[n+1];
        bool vis[n+1]={false};
        re(i,m)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // re(i,n+1)
        // {
        //     cout<<i<<": ";
        //     for(auto x:adj[i])
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        int ans=bfs(1,n,vis,adj);
        cout<<ans<<endl;
    }
}